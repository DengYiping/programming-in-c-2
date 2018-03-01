#include "stack.h"
#include <string.h>

void empty(struct stack* s){
    //empty the entire thing
    printf("Emptying Stack ");
    for(int i = s->count - 1; i >= 0; i--){
        printf("%d ", s->array[i]);
    }
    printf("\n");
    s->count = 0;
}

void push(int data, struct stack* s){
    //add one element
    if(s->count == 12){
        printf("Pushing Stack Overflow\n");
        return;
    }
    printf("Pushing %d\n", data);
    s->array[s->count] = data;
    s->count++;
}

void pop(struct stack* s){
    //remove and return the result
    if(s->count == 0){
        printf("Popping Stack Underflow\n");
        return;
    }
    s->count--;
    printf("Popping %d\n", s->array[s->count]);
    return;
}

int isEmpty(struct stack* s){
    //check if it is empty
    if(s->count == 0)
        return 1;
    else
        return 0;
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
