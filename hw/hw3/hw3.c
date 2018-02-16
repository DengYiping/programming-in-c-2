/*
    JTSK-320111
    hw3.c
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

// define the doubly linked list
typedef struct ListNode {
    char val;
    struct ListNode* next;
    struct ListNode* prev;
}ListNode;

typedef struct List {
    ListNode* first;
    ListNode* last;
}List;

List* prepend(List* lst, char val){
    if(lst->first == NULL){
        ListNode* newNode = (ListNode*) malloc(sizeof(ListNode));
        newNode->prev = NULL;
        newNode->next = NULL;
        newNode->val = val;
        lst->first = newNode;
        lst->last = newNode;
    } else {
        ListNode* newNode = (ListNode*) malloc(sizeof(ListNode));
        newNode->val = val;
        newNode->prev = NULL;

        // points to each other
        newNode->next = lst->first;
        lst->first->prev = newNode;
        //add it to the list
        lst->first = newNode;
    }
    return lst;
}

List* removeOne(List* lst, ListNode* node){
    // consider the edge cases
    if(node == lst->first && node == lst->last){
        lst->first = NULL;
        lst->last = NULL;
        free(node);
        return lst;
    }
    if(node == lst->first){
        lst->first = node->next;
        lst->first->prev = NULL;
        free(node);
        return lst;
    }
    if(node == lst->last){
        lst->last = node->prev;
        lst->last->next = NULL;
        free(node);
        return lst;
    }

    // removeOne one element from the list
    //points to each other
    node->prev->next = node->next;
    node->next->prev = node->prev;
    // release resoruces
    free(node);
    return lst;
}

List* removeOneAll(List* lst, char val){
    if(lst->first == NULL)
        return lst;
    ListNode* nextNode;
    ListNode* currentNode = lst->first;
    int isInList = 0;

    while(currentNode != NULL){
        nextNode = currentNode->next;
        if(currentNode->val == val){
            isInList = 1;
            lst = removeOne(lst, currentNode);
        }
        currentNode = nextNode;
    }
    if(!isInList)
        printf("The element is not in the list!\n");
    return lst;
}

void printList(List* lst){
    ListNode* currentNode = lst->first;
    while(currentNode != NULL){
        printf("%c ", currentNode->val);
        currentNode = currentNode->next;
    }
    printf("\n");
    return;
}

void printReverseList(List* lst){
    ListNode* currentNode = lst->last;
    while(currentNode != NULL){
        printf("%c ", currentNode->val);
        currentNode = currentNode->prev;
    }
    printf("\n");
    return;
}
void freeList(List* lst){
    // deallocate
    ListNode* currentNode = lst->first;
    ListNode* nextNode;
    while(currentNode != NULL){
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    free(lst);
    return;
}
int main(int argc, char** argv){
    char buf[100];
    int cmd;
    char input;
    List* lst = (List*) malloc(sizeof(List));
    lst->first = NULL;
    lst->last = NULL;

    while(1) {
        //getting instruction
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%d", &cmd);
        switch (cmd) {
            case 1:
                // insert
                fgets(buf, sizeof(buf), stdin);
                sscanf(buf, "%c", &input);
                lst = prepend(lst, input);
                break;
            case 2:
                // removeOne given input
                fgets(buf, sizeof(buf), stdin);
                sscanf(buf, "%c", &input);
                lst = removeOneAll(lst, input);
                break;
            case 3:
                printList(lst);
                break;
            case 4:
                printReverseList(lst);
                break;
            case 5:
                // quit
                freeList(lst);
                exit(0);
                break;
            default:
                break;
        }
    }
    return 0;
}
