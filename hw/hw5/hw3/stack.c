#include "stack.h"
#include <string.h>

void empty(struct stack* s){
    //empty the entire thing
    s->count = 0;
}

void push(char* data, struct stack* s){
    //add one element
    s->array[s->count] = data;
    s->count++;
}

char* pop(struct stack* s){
    //remove and return the result
    s->count--;
    return s->array[s->count];
}

int isEmpty(struct stack* s){
    //check if it is empty
    if(s->count > 0)
        return 0;
    else
        return 1;
}

struct stack* createStack(){
    //create a new stack
    struct stack* s = (struct stack*) malloc(sizeof(struct stack));
    s->count = 0;
    return s;
}

void freeStack(struct stack* s){
    //deallocate
    free(s);
}
