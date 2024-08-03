#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_sigint(int sig);
void handle_sighup(int sig);

int main(int argc, char *argv[]){
    signal(SIGINT, handle_sigint);
    signal(SIGHUP, handle_sighup);
    int n = atoi(argv[1]);
    for (int i = 2; i <= n; i = i + 2){
        printf("%d\n", i);
        sleep(5);
    }
    return 0;
}

void handle_sigint(int sig){
    printf("Yeah!\n");
}

void handle_sighup(int sig){
    printf("Ouch!\n");
}