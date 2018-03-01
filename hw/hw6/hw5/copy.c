#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t fsize(FILE* source){
    fseek(source, 0, SEEK_END);
    size_t size = ftell(source);
    fseek(source, 0, SEEK_SET);
    return size;
}

void copy(FILE* source, FILE* des){
    //copy the content
    unsigned char buf[64];
    size_t size = fsize(source);
    fseek(source, 0, SEEK_SET);
    while(fread(buf, sizeof(buf), 1, source) && size > 0){
        if(size < 64){
            fwrite(buf, sizeof(buf[0]), size, des);
            size = 0;
        }
        else{
            fwrite(buf, sizeof(buf[0]), 64, des);
            size -= 64;
        }
    }
    return;
}

int main(int argc, char** argv){
    char buf[100];
    char fname[100];
    int file_num;
    
    //reading the file number
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &file_num);

    FILE* des = fopen("output.txt", "w"); //open in write mode
    FILE* source;
    for(int i = 0; i < file_num; i++){
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%s", fname);
        source = fopen(fname, "r");
        copy(source, des);
        fwrite("\n", 1, 1, des);
        fclose(source);
    }
    fclose(des);
}
