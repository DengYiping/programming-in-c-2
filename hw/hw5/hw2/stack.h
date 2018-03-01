#include <stdio.h>
#include <stdlib.h>

struct stack {
    unsigned int count;
    int array[32]; //at most 32 bit
};

void push(int data, struct stack* s);
int pop(struct stack* s);
void empty(struct stack* s);
int isEmpty(struct stack* s);
struct stack* createStack();
void freeStack(struct stack* s);
