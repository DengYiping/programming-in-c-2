#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    char name[30];
    int age;
} person;

void swap_memory(void* p1, void* p2, void* tmp, size_t mem_size)
{
    memcpy(tmp, p1, mem_size);
    memcpy(p1, p2, mem_size);
    memcpy(p2 , tmp, mem_size);
}

void bubblesort(void* ptr, size_t count, size_t size, int (*comp)(const void *, const void *)){
    // no need to sort
    if(count <= 1)
        return;

    // for swapping elements
    void* tmp = malloc(size);

    int swapped = 1;
    while(swapped){
        swapped = 0;
        for(int i = 1; i < count; i++){
            if(comp(ptr + (i - 1) * size, ptr + i * size) > 0){
                swap_memory(ptr + (i - 1) * size, ptr + i * size, tmp, size); //swap elements
                swapped = 1;
            }
        }
    }
    free(tmp);
    return;
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

void printPersons(person* ps, int num){
    // print the result
    for(int i = 0; i < num; i++){
        printf("{%s, %d}; ", ps[i].name, ps[i].age);
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

    person* arr = (person*) malloc(sizeof(person) * n);

    for(int i = 0; i < n; i++){
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%s", arr[i].name);
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%d", &(arr[i].age));
    }

    bubblesort(arr, n, sizeof(person), cmp_name);
    printPersons(arr, n);
    bubblesort(arr, n, sizeof(person), cmp_age);
    printPersons(arr, n);
}
