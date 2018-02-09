/*
    JTSK-320111
    p2.c
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
    char buf[100];
    char s1[100];
    char s2[100];

    //reading
    fgets(s1, sizeof(buf), stdin);
    fgets(s2, sizeof(buf), stdin);

    int size1 = strlen(s1) - 1;
    int size2 = strlen(s2) - 1;

    // + 1 because the terminating \0
    char* s3 = (char*) malloc(sizeof(char) * (size1 + size2 + 1));
    for(int i = 0; i < size1; i++){
        s3[i] = s1[i];
    }
    for(int i = 0; i < size2; i++){
        s3[i + size1] = s2[i];
    }
    s3[size1 + size2] = '\0'; //terminating the string
    printf("Result of concatenation: %s\n", s3);
    free(s3);
}
