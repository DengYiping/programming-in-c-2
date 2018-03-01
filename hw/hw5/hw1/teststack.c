#include "stack.h"

int main(int argc, char** argv){
    //the test case
    char buf[100]; //buffer
    int data;
    char cmd; //command
    struct stack* s = createStack();
    while(1){
        //forever
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%c", &cmd);
        switch(cmd){
            case 's':
                fgets(buf, sizeof(buf), stdin);
                sscanf(buf, "%d", &data);
                push(data, s);
                break;
            case 'p':
                pop(s);
                break;
            case 'e':
                empty(s);
                break;
            case 'q':
                freeStack(s);
                printf("Quit\n");
                return 0;
        }
    }
    return 0;
}


