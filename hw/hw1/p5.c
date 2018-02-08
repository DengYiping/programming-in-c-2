/*
    JTSK-320111
    p5.c
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <stdio.h>

int main(int argc, char** argv){
    char buf[100];
    unsigned char c;

    //reading
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%c", &c);

    // pirnt the decimal
    printf("The decimal representation is: %d\n", c);
    //printing start
    //in the backward order
    printf("The backwards binary representation is: ");
    for(int i = 0; i < 8; i++){
        // make sure it is significant bit
        if(!(c & ~0 << i))
            break;
        if(c & 1 << i)
            printf("1");
        else
            printf("0");
    }
    printf("\n");

    return 0;
}
