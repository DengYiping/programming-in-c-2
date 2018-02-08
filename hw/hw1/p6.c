/*
    JTSK-320111
    p6.c
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
    printf("The binary representation is: ");
    char bin[9];
    for(int i = 0; i < 8; i++){
        if(c & 1 << i)
            bin[7 - i] = '1';
        else
            bin[7 - i] = '0';
    }
    bin[8] = '\0'; // make sure it terminates
    printf("%s\n", bin);

    return 0;
}
