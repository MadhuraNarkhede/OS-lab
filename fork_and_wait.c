#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

void bubble_sort(int arr[20],int n)
{
 int i,j,temp;
 
 for( i=0;i<n-1;i++)
 {
  for(j=1;j<n-1;j++)
  {
   if(arr[j]>arr[j+1])
   {
    temp=arr[j];
    arr[j]=arr[j+1];
    arr[j+1]=arr[j];
    }
  }
}
}

void fork1()
{
 int arr[20],n;
 
 printf("\n Enter the number of elements in array(max 20) : ");
 scanf("%d",&n);
 printf("\n Enter the elements : ");
 for(int i=0;i<n;i++)
 {
  scanf("%d",&arr[i]);
  }
  
  int pid=fork();
   
   if(pid==0)
   {
    sleep(5);
    printf("\n child process ");
    printf("\n child process id=%d\n",getpid());
    
    bubble_sort(arr,n);
    
    printf("Elements sorted by child process by :");
    for(int i=0;i<n;i++)
 {
  printf("%d",arr[i]);
    
  }
  printf("\n parent process ");
    printf("\n parent process id=%d\n",getpid());
    system("ps -x");                 
  
  printf("\n");     
  }
 else
 {
 printf("\n parent process ");
    printf("\n parent process id=%d\n",getpid());
    
    bubble_sort(arr,n);
    
    printf("Elements sorted by parent process by :");
    for(int i=0;i<n;i++)
 {
  printf("%d",arr[i]);
  printf("\b");
  }
  
  printf("\n");
  }
  }
  
  int main()
  {
   fork1();
   return 0;
   }
  
