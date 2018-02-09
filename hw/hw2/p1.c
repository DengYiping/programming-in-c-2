/*
    JTSK-320111
    p1.c
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv){
    char buf[100]; //buffer

    //reading
    int num; //size of the input
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &num);

    float* darr = (float*) malloc(sizeof(float) * num);
    float* ptr_idx = darr;

    //reading the array
    for(int i = 0; i < num; i++){
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%f", darr + i);
    }
    //calculation
    while(num--){
        if(*ptr_idx < 0.0)
            break;
        ptr_idx++;
    }
    printf("Before the first negative value: %ld elements\n", ptr_idx - darr);
    free(darr);
}

