/*
    JTSK-320111
    linked_list.h
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
/*
 Inserts a new int at the beginning of the list         list: list where element should be inserted             value: integer to be inserted
 Returns the updated list
 */
struct list {
    int info;
    struct list* next;
};

void dispose_list(struct list* my_list);
void print_elements(struct list* my_list);
struct list* push_back(struct list* my_list, int value);
struct list* push_front(struct list *my_list, int value);
