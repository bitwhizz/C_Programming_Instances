#include <stdio.h>
#include<stdbool.h>
#include <signal.h>
#include<unistd.h>
#include<pthread.h>

volatile bool done = false;

void *tfunc(void *arg){
    sleep(1);
    done = false;
    return NULL;
}

int main(void){
    pthread_t t1;
    pthread_create(&t1,NULL,tfunc,NULL);

    printf("waiting...\n");
    while(!done){
        sleep(1);
    }
    printf("ok. Moving on \n");
}