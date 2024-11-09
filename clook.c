
#include <stdio.h>
#include <stdlib.h>

void clook(int req[], int n, int head) {
int total_seek = 0, i;
int left[100], right[100], l_count = 0, r_count = 0;
for (i = 0; i < n; i++) {
if (req[i] < head) left[l_count++] = req[i];
if (req[i] > head) right[r_count++] = req[i];
}
qsort(left, l_count, sizeof(int), cmpfunc);
qsort(right, r_count, sizeof(int), cmpfunc);
printf("C-LOOK Seek Sequence: ");
for (i = 0; i < r_count; i++)
{
total_seek += abs(head - right[i]);
head = right[i];
printf("%d ", head);
}
for (i = 0; i < l_count; i++)
{
total_seek += abs(head - left[i]);
head = left[i];
printf("%d ", head);
}
printf("\nTotal Seek Time (C-LOOK): %d\n", total_seek);
}

int cmpfunc(const void *a, const void *b)
{
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



clook(req, n, head);
return 0;
}
/*
OUTPUT
gcc disk_scheduling.c -o disk_scheduling
./disk_scheduling
Enter number of requests: 8
Enter request sequence: 176 79 34 60 92 11 41 114
Enter initial head position: 50

C-LOOK Seek Sequence: 60 79 92 114 176 41 34 11
Total Seek Time (C-LOOK): 315
*/
