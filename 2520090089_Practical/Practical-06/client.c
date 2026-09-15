#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO1 "client_to_server"
#define FIFO2 "server_to_client"

int main()
{
    char message[100];
    int fd1, fd2;

    fd1 = open(FIFO1, O_WRONLY);

    strcpy(message, "Hello Server!");

    write(fd1, message, strlen(message) + 1);

    close(fd1);

    fd2 = open(FIFO2, O_RDONLY);

    read(fd2, message, sizeof(message));

    printf("Server: %s\n", message);

    close(fd2);

    return 0;
}
