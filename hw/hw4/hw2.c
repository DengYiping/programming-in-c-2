#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef void (*print_t)(char*);

void printUpper(char* str){
    //print the upper case
    while(*str != '\0'){
        printf("%c", toupper(*str));
        str++;
    }
    return;
}

void printLower(char* str){
    //print the lower case
    while(*str != '\0'){
        printf("%c", tolower(*str));
        str++;
    }
    return;
}

void printSwitchCase(char* str){
    //switch upper and lower case
    while(*str != '\0'){
        if(isupper(*str))
            printf("%c", tolower(*str));
        else if(islower(*str))
            printf("%c", toupper(*str));
        else
            printf("%c", *str);
        str++;
    }
    return;
}

void printQuit(char* str){
    //exit the program
    exit(0);
    return;
}

int main(int argc, char** argv){
    char buf[100];
    char str[100];
    int cmd;
    print_t fun_arr[] = {printUpper, printLower, printSwitchCase, printQuit};
    // reading the original string
    fgets(str, sizeof(str), stdin);

    while(1){
        // read the command
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%d", &cmd);
        // calling the function
        fun_arr[cmd -1](str);
    }
}
