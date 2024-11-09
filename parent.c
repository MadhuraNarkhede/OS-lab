#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void tostring(char str[], int num) {
    sprintf(str, "%d", num);
}

int main(int argc, char *argv[]) {
    printf("\nThis is the main process:\nProcess Id: %d\nParent Id: %d", getpid(), getppid());

    int arr[] = {10, 5, 1, 60, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);

    pid_t cpid = fork();
    if (cpid > 0) {
        wait(NULL);
        printf("\nParent Exiting!!\n");
    } else if (cpid == 0) {
        char *arrChar[n + 2];
        arrChar[0] = "child"; // Name of executable
        for (int i = 0; i < n; i++) {
            arrChar[i + 1] = malloc(20);
            tostring(arrChar[i + 1], arr[i]);
        }
        arrChar[n + 1] = NULL;
        execv("./child", arrChar);
        perror("execv failed");
        for (int i = 1; i <= n; i++) free(arrChar[i]); // Free memory
        exit(1);
    } else {
        perror("fork failed");
    }
    return 0;
}

