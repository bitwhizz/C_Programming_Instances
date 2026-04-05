/*
346. Moving Average from Data Stream

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int sum;
    int n;
    int size;
} MovingAverage;


/** Initialize your data structure here. */
MovingAverage* movingAverageCreate(int size) {
    int *p;
    MovingAverage *m;
 
    m = calloc(1, sizeof(*m));
    p = calloc(size, sizeof(*p));
    //assert(m && p);
    m->data = p;
    m->sum = 0;
    m->n = 0;
    m->size = size;
 
    return m;
}

double movingAverageNext(MovingAverage* obj, int val) {
    int *slot, old;

    slot = &obj->data[obj->n % obj->size];
    old = *slot;
    *slot = val;
    obj->n++;
    obj->sum = obj->sum - old + val;

    if (obj->n < obj->size) return (double)obj->sum / (double)obj->n;

    return (double)obj->sum / (double)obj->size;
}

void movingAverageFree(MovingAverage* obj) {
    free(obj->data);
    free(obj);
}

int main(void)
{
    MovingAverage *m3 = movingAverageCreate(3);

    int values[] = {112,114,115,113,116};

    int size = sizeof(values)/ sizeof(values[0]);
    int iter;
    double result = 0;

    for (iter = 0; iter < size ;iter++){
        result = movingAverageNext(m3,values[iter]);
        printf("%lf ",result);
    }

    printf("\n");

    movingAverageFree(m3);

    return 0;
}

       
/**
 * Your MovingAverage struct will be instantiated and called as such:
 * struct MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);
 * movingAverageFree(obj);
 */
