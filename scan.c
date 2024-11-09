
#include <stdio.h>
#include <stdlib.h>

void scan(int req[], int n, int head, int disk_size, int direction)
{
int total_seek = 0, i;
int left[100], right[100], l_count = 0, r_count = 0;
if (direction == 1) right[r_count++] = disk_size;
if (direction == -1) left[l_count++] = 0;
for (i = 0; i < n; i++)
{
if (req[i] < head) left[l_count++] = req[i];
if (req[i] > head) right[r_count++] = req[i];
}
qsort(left, l_count, sizeof(int), cmpfunc);
qsort(right, r_count, sizeof(int), cmpfunc);
printf("SCAN Seek Sequence: ");
if (direction == -1)
{
for (i = l_count - 1; i >= 0; i--)
{
total_seek += abs(head - left[i]);
head = left[i];
printf("%d ", head);
}
for (i = 0; i < r_count; i++)
{
total_seek += abs(head - right[i]);
head = right[i];
printf("%d ", head);
}
} else {
for (i = 0; i < r_count; i++)
{
total_seek += abs(head - right[i]);
head = right[i];
printf("%d ", head);
}
for (i = l_count - 1; i >= 0; i--)
{
total_seek += abs(head - left[i]);
head = left[i];
printf("%d ", head);
}
}
printf("\nTotal Seek Time (SCAN): %d\n", total_seek);
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
printf("Enter disk size: ");
scanf("%d", &disk_size);
printf("Enter direction (1 for up, -1 for down): ");
scanf("%d", &direction);
sstf(req, n, head);
scan(req, n, head, disk_size, direction);
clook(req, n, head);
return 0;
}

