#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

sem_t e;
sem_t f;
sem_t s;

int buff[5];
int in=0;
int out=0;

void* producer(void * arg){
    while(1){
        
    
    sem_wait(&e);
    sem_wait(&s);
    
    int data=rand();
    buff[in]=data;
    
    printf("/n Product %d has entered in %lu successfully /n",data,pthread_self());
    in=(in+1)%5;
    
    sem_post(&s);
    sem_post(&f);
    sleep(1);
}
return NULL;
    
}

void* consumer(void * arg){
    while(1){
        
    
    sem_wait(&f);
    sem_wait(&s);
    
    int data=buff[out];
    
    printf("/n Product %d has consumed in %lu successfully /n",data,pthread_self()); 
    out=(out+1)%5;
    
    sem_post(&s);
    sem_post(&e);
    sleep(2);
}
return NULL;
    
}

int main()
{
     srand(time(NULL));
     
    pthread_t tid[5];
    pthread_t cid;
    
    sem_init(&e,0,5);
    sem_init(&f,0,0);
    sem_init(&s,0,1);
    
    for(int i=0;i<5;i++)
    {
        pthread_create(&tid[i],NULL,producer,NULL);
    }
    
    pthread_create(&cid,NULL,consumer,NULL);
    
     for(int i=0;i<5;i++)
    {
        pthread_join(tid[i],NULL);
    }
}
