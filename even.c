#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_sighandle(int sig);


int main(int argc, char *argv[]){
    signal(SIGINT, &handle_sighandle);
    signal(SIGHUP, &handle_sighandle);
    int n = atoi(argv[1]);
    for (int i = 0; i < n; i = i + 2){
        printf("%d\n", i);
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
