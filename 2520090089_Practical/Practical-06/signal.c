#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig)
{
    if (sig == SIGINT)
        printf("\nSIGINT received!\n");

    else if (sig == SIGTERM)
        printf("SIGTERM received!\n");

    else if (sig == SIGUSR1)
        printf("SIGUSR1 received!\n");
}

int main()
{
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);
    signal(SIGUSR1, handle_signal);

    printf("Process ID: %d\n", getpid());
    printf("Waiting for signals...\n");

    while (1)
    {
        sleep(1);
    }

    return 0;
}
