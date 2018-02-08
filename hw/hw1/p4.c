/*
    JTSK-320111
    p4.c
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#define INTERMEDIATE
int scalarProduct(int* v1, int* v2, int num){
#ifdef INTERMEDIATE
    printf("The intermediate product values are:\n");
#endif
    int sum = 0;
    int prod;
    for(int i = 0; i < num; i++){
        prod = v1[i] * v2[i];
#ifdef INTERMEDIATE
        printf("%d\n", prod);
#endif
        sum += prod;
    }
    //return the result
    return sum;
}

int main(int argc, char** argv){
    char buf[100];
    int d;

    //read the dimension
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &d);

    //read the vector
    int* v1 = (int*) malloc(sizeof(int) * d);
    int* v2 = (int*) malloc(sizeof(int) * d);
    for(int i = 0; i < d; i++){
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%d", v1 + i);
    }
    for(int i = 0; i < d; i++){
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%d", v2 + i);
    }

    //print the result
    printf("The scalar product is: %d\n", scalarProduct(v1, v2, d));

    //free the resources
    free(v1);
    free(v2);

    return 0;
}
