#include <stdio.h>
#include<stdbool.h>
#include <signal.h>
#include<unistd.h>
#include<pthread.h>

volatile bool sigarrived = false;

void handler(int sig){
    if(sig == SIGINT){
        sigarrived = true;
    }
}

int main(void){
    pthread_t t1;


    printf("waiting...Press Ctrl-C to move on\n");

    signal(SIGINT, handler);
    while(!sigarrived){}
    printf("ok. Moving on \n");
}