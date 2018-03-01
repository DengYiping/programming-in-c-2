#include "stack.h"

void buildStack(int dec, struct stack* s){
    // build up the stack of digits
    if(dec == 0)
        return;
    push(dec % 2, s);
    buildStack(dec / 2, s);
    return;
}

void printStack(struct stack* s){
    while(!isEmpty(s))
        //print a digit
        printf("%d", pop(s));
    return;
}

int main(int argc, char** argv){
    //reading
    char buf[100];
    int dec;
    struct stack* s = createStack();
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &dec);
    printf("The binary representation of %d is ", dec);
    buildStack(dec, s);
    printStack(s);
    freeStack(s);
    printf(".\n"); //change line

    return 0;
}
