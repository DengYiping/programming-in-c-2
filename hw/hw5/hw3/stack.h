#include <stdio.h>
#include <stdlib.h>

struct stack {
    unsigned int count;
    char* array[12]; //at most 12 words
};

void push(char* data, struct stack* s);
char* pop(struct stack* s); //pop a word
void empty(struct stack* s);
int isEmpty(struct stack* s);
struct stack* createStack();
void freeStack(struct stack* s);
