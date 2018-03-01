#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 100

// store the index of the password and everything
typedef struct pair{
    char* key;
    int value;
} pair;

// using a linked list to store the info
typedef struct ListNode{
    pair* data;
    struct ListNode* next;
} ListNode;

int get(char* key, ListNode* head){
    //search the key in the list of key-value pair
    // return the position of file
    if(head == NULL)
        return -1;
    if(strcmp(head->data->key, key) == 0)
        return head->data->value;
    return get(key, head->next);
}

ListNode* put(char* key, int value, ListNode* head){
    //insert elements into the list
    pair* p = (pair*) malloc(sizeof(pair));
    p->key = key;
    p->value = value;
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    node->data = p;
    node->next = head;
    return node;
}

void printList(ListNode* head){
    if(head == NULL)
        return;
    printf("name: %s\n", head->data->key);
    printList(head->next);
    return;
}


void clear(ListNode* head){
    // release every resources
    if(head == NULL)
        return;
    ListNode* nxt = head->next;

    free(head->data->key);
    free(head->data);
    free(head);
    clear(nxt);
}

char* readline(FILE* fp){
    char* line = (char*) malloc(sizeof(char) * LINE_LEN);
    if(fgets(line, LINE_LEN * sizeof(char), fp)){
        for(int i = 0; i < LINE_LEN;i++){
            if(line[i] == '\n')
                line[i] = '\0';
        }
        return line;
    }
    return NULL;
}

int main(int argc, char** argv){
    FILE* fptr;
    char fname[100];
    ListNode* head = NULL;

    //get the file name
    fgets(fname, sizeof(fname), stdin);
    for(int i = 0; i < 100; i++){
        //remove the line break
        if(fname[i] == '\n'){
            fname[i] = '\0';
        }
    }

    fptr = fopen(fname, "r");
    if(fptr == NULL)
        exit(1); //exit on error

    char* line;
    char* line2;
    char* line3;
    int pos;

    // read all the entries
    while((line = readline(fptr))){
        head = put(line, ftell(fptr), head);
        free(readline(fptr)); //skip a line by directly free the space
    }
    printList(head);
    while(1){
        line = readline(stdin);
        if(strcmp(line, "exit") == 0){
            free(line);
            break;
        }
        line2 = readline(stdin);
        pos = get(line, head);
        if(pos == -1)
            printf("Access to user %s is denied.\n", line);
        else {
            fseek(fptr, pos, SEEK_SET);
            line3 = readline(fptr);
            if(strcmp(line2, line3) == 0){
                printf("Access to user %s is granted.\n", line);
            } else {
                printf("Access to user %s is denied.\n", line);
            }
        }
        free(line);
        free(line2);
        free(line3);
    }
    clear(head);
    fclose(fptr);
}
