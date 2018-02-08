#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char* itobin(int n){
    char* s = malloc(33 * sizeof(char));
    unsigned int mask = 0;
    for(int i = 0; i < 32; i++){
        mask = pow(2, i);
        if(mask & n)
            s[31 - i] = '1';
        else
            s[31 - i] = '0';
    }
    s[32] = '\0';
    return s;
}

int main(int argc, char** argv){
    int i = atoi(argv[1]);
    char* s = itobin(i);
    printf("%s\n", s);
    free(s);
    return 0;
}
