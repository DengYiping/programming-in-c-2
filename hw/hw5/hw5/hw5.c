#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    char name[32]; //at most 30 character
    // 1 \n and 1 \0
    int age;
} person;

void swap_memory(void* p1, void* p2, void* tmp, size_t mem_size)
{
    memcpy(tmp, p1, mem_size);
    memcpy(p1, p2, mem_size);
    memcpy(p2 , tmp, mem_size);
}


int cmp_name(const void* p1, const void* p2){
    //cast back and
    const person* person1 = (person*) p1;
    const person* person2 = (person*) p2;
    int cmp_rst = strcmp(person1->name, person2->name);
    if(cmp_rst)
        return cmp_rst;
    return (person1->age < person2->age) ? -1 : 1;
}
int cmp_age(const void* p1, const void* p2){
    //cast back and
    const person* person1 = (person*) p1;
    const person* person2 = (person*) p2;
    if(person1->age == person2->age)
        return strcmp(person1->name, person2->name);
    return (person1->age < person2->age) ? -1 : 1;
}

int cmp_dec(const void* p1, const void* p2){
    if(*((float*) p1) < *((float*) p2))
        return 1;
    return -1;
}

void printPersons(person* ps, int num){
    // print the result
    for(int i = 0; i < num; i++){
        printf("%s:%d", ps[i].name, ps[i].age);
        if(i != num -1)
            printf(" ");
    }
    printf("\n");
    return;
}

int main(int argc, char** argv){
    char buf[100];
    int n; //number of people

    // read the number
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &n);

    person* parr = (person*) malloc(sizeof(person) * n);
    float* farr = (float*) malloc(sizeof(float) * n);

    //reading the float
    for(int i = 0; i < n; i++){
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%f", farr + i); //dump the data
    }

    //read people
    for(int i = 0; i < n; i++){
        fgets(parr[i].name, sizeof(char) * 32, stdin);
        //dump the name
        for(int j = 0; j < 32; j++){
            if(parr[i].name[j] == '\n')
                parr[i].name[j] = '\0';
        }
        //remove the \n
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%d", &(parr[i].age));
    }
    printf("Decreasingly sorted floats:\n");
    qsort(farr, n, sizeof(float), cmp_dec);
    for(int i = 0; i < n; i++){
        printf("%.3f", farr[i]);
        if(i != n - 1)
            printf(" ");
    }
    printf("\n");
    printf("Alphabetically sorted structs (name):\n");
    qsort(parr, n, sizeof(person), cmp_name);
    printPersons(parr, n);
    printf("Increasingly sorted structs (age):\n");
    qsort(parr, n, sizeof(person), cmp_age);
    printPersons(parr, n);
    free(parr);
    free(farr);
}
