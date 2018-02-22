#include <stdio.h>
#include <stdlib.h>

// function name is already a pointer
int normal_cmp(const void* a, const void* b){
    // cast to integer pointer
    if(*(const int*)a < *(const int*)b)
        return -1;
    return 1;
}

int reverse_cmp(const void* a, const void* b){
    //cast to integer pointer
    if(*(const int*)a < *(const int*)b)
        return 1;
    return -1;
}

void printArr(int* arr, int num){
    // print a array
    for(int i = 0; i < num; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char** argv){
    char buf[100];
    int n; //number of elements
    int* darr; //dynamically allocate this
    char cmd; // command
    // get n
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &n);

    darr = (int*) malloc(sizeof(int) * n);
    // reading
    for(int i = 0; i < n; i++){
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%d", darr + i);
    }

    while(1){
        // get the command
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%c", &cmd);
        switch(cmd){
            case 'a':
                // asending
                qsort(darr, n, sizeof(int), normal_cmp);
                printArr(darr, n);
                break;
            case 'd':
                // decending
                qsort(darr, n, sizeof(int), reverse_cmp);
                printArr(darr, n);
                break;
            case 'e':
                // exit the program
                free(darr);
                exit(0);
                break;
            default:
                break;
        }
    }

    return 0;
}

