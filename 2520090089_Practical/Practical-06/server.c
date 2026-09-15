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

    mkfifo(FIFO1, 0666);
    mkfifo(FIFO2, 0666);

    printf("Server waiting for client...\n");

    fd1 = open(FIFO1, O_RDONLY);

    read(fd1, message, sizeof(message));
    printf("Client: %s\n", message);

    close(fd1);

    fd2 = open(FIFO2, O_WRONLY);

    strcpy(message, "Hello Client, message received!");

    write(fd2, message, strlen(message) + 1);

    close(fd2);

    unlink(FIFO1);
    unlink(FIFO2);

    return 0;
}
