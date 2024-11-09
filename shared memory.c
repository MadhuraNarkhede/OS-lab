Practical no.11
//server.c
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
struct data
{
char str[100];
int flag;
};
void main()
{
key_t key = ftok("abc.txt",'A');
int shmid = shmget(key, 1024, 0777|IPC_CREAT);
struct data*d = shmat(shmid, NULL, 0);
d->flag = 0;
printf("\n Enter data: ");
gets(d->str);
d->flag=1;
while(d->flag!= -1)
{
printf("\n waiting \n ");
sleep(2);
}
shmdt(d);
}
//client.c
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
struct data
{
char str[100];
int flag;
};
void main()
{
key_t key = ftok("abc.txt",'A');
int shmid = shmget(key, 1024, 0777|IPC_CREAT);
struct data*d = shmat(shmid, NULL, 0);
d->flag = 0;
while(d->flag!= 1)
{
printf("\n waiting \n ");
sleep(2);
}
printf("\n Accepted data is: ");
printf("%s", d->str);
d->flag=-1;
printf("\n");
shmdt(d);
shmctl(shmid, IPC_RMID, NULL);
}

