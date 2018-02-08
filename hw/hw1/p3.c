/*
    JTSK-320111
    p3.c
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <stdio.h>

#define MIN(A, B) ((A > B) ? (B) : (A))
#define MIN3(A, B, C) ((MIN(A, B) > MIN(B, C)) ? MIN(B, C) : MIN(A, B))
#define MAX(A, B) ((A > B) ? (A) : (B))
#define MAX3(A, B, C) ((MAX(A, B) > MAX(B, C)) ? MAX(A, B) : MAX(B, C))
#define MIDRANGE(A, B, C) ((MIN3(A, B, C) + MAX3(A, B, C)) / 2.0)

int main(int argc, char** argv){
    char buf[100];

    int a, b, c;

    //reading
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &a);
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &b);
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &c);

    float result = MIDRANGE(a, b, c);
    printf("The mid-range is: %.6f\n", result);
    return 0;
}
