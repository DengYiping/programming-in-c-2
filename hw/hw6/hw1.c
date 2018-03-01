#include <stdio.h>

int isSeperator(char c){
    // check if a character is a seperator
    switch(c){
        case ' ':
        case ',':
        case '?':
        case '!':
        case '.':
        case '\t':
        case '\r':
        case '\n':
            return 1;
            break;
        default:
            return 0;
            break;
    }
}
int main(int argc, char** argv){
    char fname[100];
    fgets(fname, sizeof(fname), stdin);
    //retrieve the name of the file
    for(int i = 0; i < 100; i++){
        if(fname[i] == '\n')
            fname[i] = '\0'; //terminate the string
    }

    FILE* fptr = fopen(fname, "r");
    int count = 0;
    char ch;
    char prevChar = '\n';
    while((ch = getc(fptr)) != EOF){
        //don't increase if you have done it
        if(isSeperator(ch) && !isSeperator(prevChar))
            count++;
        prevChar = ch;
    }
    printf("The file contains %d words.\n", count);
    fclose(fptr);

    return 0;
}
