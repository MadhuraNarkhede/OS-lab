Practical no. 10
//Server.c
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
int main() {
const char *myfifo = "/tmp/myfifo";
mkfifo(myfifo, 0666);
char str1[80];
while (1)
{
int fd = open(myfifo, O_RDONLY);
read(fd, str1, sizeof(str1));
printf("User1: %s\n", str1);
close(fd);
}
return 0;
}
//client.c
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
int main()
{
const char *myfifo = "/tmp/myfifo";
char str2[80];
while (1) {
int fd = open(myfifo, O_WRONLY);
fgets(str2, sizeof(str2), stdin);
kB write(fd, str2, strlen(str2) + 1);
close(fd);
}
return 0;
}
/*
//output of client
student@student:~/Documents$ gcc client.c -o client
student@student:~/Documents$ ./client
HELLO I AM FINE
//output of server
tudent@student:~/Documents$ gcc server.c -o server
student@student:~/Documents$ ./server
User1: HELLO I AM FINE
*/
