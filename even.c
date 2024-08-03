#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_sighandle(int sig);


int main(int argc, char *argv[]){
    signal(SIGINT, &handle_sighandle);
    signal(SIGHUP, &handle_sighandle);
    int n = atoi(argv[1]);
    printf("%d\n", 0);
    for (int i = 2; i <= n; i = i + 2){
        printf("%d\n", i);
        sleep(5);
    }
    return 0;
}

void handle_sighandle(int sig){
    if (sig == SIGHUP){
        printf("Ouch!\n");

    } else if (sig == SIGINT){
        printf("Yeah!\n");

    }
}
