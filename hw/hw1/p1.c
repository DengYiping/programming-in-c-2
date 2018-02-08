/*
    JTSK-320111
    p1.c
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <stdio.h>

#define SWAP(A, B, T) {T C = A; A = B; B = C;}

int main(int argc, char** argv){
    char buf[100]; //buffer
    int i1, i2;
    double f1, f2;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &i1);
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &i2);
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%lf", &f1);
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%lf", &f2);
    // get the input
    //
    //swap the variable
    SWAP(i1, i2, int);
    SWAP(f1, f2, double);
    //print the result
    printf("After swapping:\n");
    printf("%d\n", i1);
    printf("%d\n", i2);
    printf("%lf\n", f1);
    printf("%lf\n", f2);

    return 0;
}
    
