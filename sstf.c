#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void c_look(int req[], int n, int head) {
    int total_seek = 0, i;

    int left[100], right[100], l_count = 0, r_count = 0;

    for (i = 0; i < n; i++) {
        if (req[i] < head) {
            left[l_count++] = req[i];
        } else if (req[i] > head) {
            right[r_count++] = req[i];
        }
    }

    qsort(left, l_count, sizeof(int), cmpfunc);
    qsort(right, r_count, sizeof(int), cmpfunc);

    printf("\nC-LOOK sequence is as follows: \n");
    printf("%d ", head);

    // Process right requests
    for (i = 0; i < r_count; i++) {
        total_seek += abs(head - right[i]);
        head = right[i];
        printf("%d ", head);
    }

    // Jump to the first left request
    if (l_count > 0) {
        total_seek += abs(head - left[0]);
        head = left[0];
        printf("%d ", head);
    }

    // Process left requests
    for (i = 0; i < l_count; i++) {
        total_seek += abs(head - left[i]);
        head = left[i];
        printf("%d ", head);
    }

    printf("\nTotal Seek Time is: %d\n", total_seek);
}

int main() {
    int n, i, req[100], head;

    printf("\nEnter the number of requests: ");
    scanf("%d", &n);

    printf("\nEnter the sequence: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("\nEnter the initial position of head: ");
    scanf("%d", &head);

    c_look(req, n, head);

    return 0;
}
