/*
    JTSK-320111
    use_linked_list.c
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include "linked_list.h"
int main(int argc, char** argv){
    char buf[100]; // buffer
    int input;
    char cmd;
    struct list* lst = NULL;

    while(1){
        // read the command
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%c", &cmd);
        switch(cmd){
            case 'a':
                // read the int
                fgets(buf, sizeof(buf), stdin);
                sscanf(buf, "%d", &input);
                // insertion
                lst = push_back(lst, input);
                break;
            case 'b':
                fgets(buf, sizeof(buf), stdin);
                sscanf(buf, "%d", &input);
                // insertion
                lst = push_front(lst, input);
                break;
            case 'r':
                if(lst == NULL)
                    break;
                    // invalid operation
                struct list* tmp = lst;
                lst = lst->next;
                free(tmp);
                break;
            case 'p':
                print_elements(lst); // simply print them
                break;
            case 'q':
                dispose_list(lst);
                exit(0); // quit the program
                break;
            default:
                break;
        }
    }

    return 0;
}
