#include <stdio.h>
#include <stdlib.h>

void sstf(int req[], int n, int head)
{
int total_seek = 0, min, diff, idx, i, j;
int visited[100] = {0};
printf("SSTF Seek Sequence: ");
for (i = 0; i < n; i++)
{
min = 1000;
idx = -1;
for (j = 0; j < n; j++)
{
if (!visited[j])
{
diff = abs(req[j] - head);
if (diff < min)
{
min = diff;
idx = j;
}
}
}
visited[idx] = 1;
total_seek += abs(req[idx] - head);
head = req[idx];
printf("%d ", head);
}
printf("\nTotal Seek Time (SSTF): %d\n", total_seek);
}

int cmpfunc(const void *a, const void *b){
return (*(int *)a - *(int *)b);
}

int main() {
int n, i, head, disk_size, direction;
int req[100];
printf("Enter number of requests: ");
scanf("%d", &n);
printf("Enter request sequence: ");
for (i = 0; i < n; i++)
{
scanf("%d", &req[i]);
}
printf("Enter initial head position: ");
scanf("%d", &head);
printf("Enter disk size: ");
scanf("%d", &disk_size);
printf("Enter direction (1 for up, -1 for down): ");
scanf("%d", &direction);
sstf(req, n, head);
scan(req, n, head, disk_size, direction);
clook(req, n, head);
return 0;
}
/*
OUTPUT
gcc disk_scheduling.c -o disk_scheduling
./disk_scheduling
Enter number of requests: 8
Enter request sequence: 176 79 34 60 92 11 41 114

SSTF Seek Sequence: 41 60 34 79 92 114 176
Total Seek Time (SSTF): 210
SCAN Seek Sequence: 60 79 92 114 176 200 41 34 11 0
Total Seek Time (SCAN): 390
C-LOOK Seek Sequence: 60 79 92 114 176 41 34 11
Total Seek Time (C-LOOK): 315
*/
