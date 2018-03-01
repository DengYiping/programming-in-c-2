#include <stdio.h>
#include <stdlib.h>

struct stack {
    unsigned int count;
    int array[12];
};

void push(int data, struct stack* s);
void pop(struct stack* s);
void empty(struct stack* s);
int isEmpty(struct stack* s);
struct stack* createStack();
void freeStack(struct stack* s);
