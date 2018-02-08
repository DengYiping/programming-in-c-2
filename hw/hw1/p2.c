/*
    JTSK-320111
    p2.c
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <stdio.h>

#define LEASTSIGBIT(A) (A & 1)

int main(int argc, char** argv){
    unsigned char c;
    char buf[100];

    //reading
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%c", &c);

    //output
    printf("The decimal representation is: %d\n", c);
    printf("The least significant bit is: %d\n", LEASTSIGBIT(c));

    return 0;
}

