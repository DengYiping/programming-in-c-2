/*
    JTSK-320111
    p4.c
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
void printMatrix(int** mat, int m, int n){
    for(int idx = 0; idx < m; idx++){
        for(int idx1 = 0; idx1 < n; idx1++){
            if(idx1 == (n - 1))
                // treat the last element differently
                printf("%d \n", mat[idx][idx1]);
            else
                //normal print
                printf("%d ", mat[idx][idx1]);
        }
    }
}

int** allocateMatrix(int m, int n){
    //dynamically allocate the matrix
    int** table = (int**) malloc(sizeof(int*) * m);
    for(int i = 0; i < m; i++){
        table[i] = (int*) malloc(sizeof(int*) * n);
    }
    return table;
}

void freeMatrix(int** mat, int m){
    //free the resources
    for(int i = 0; i < m; i++){
        free(mat[i]);
    }
    free(mat);
}


int*** allocateMatrix3d(int m, int n, int p){
    int*** mat3d = (int***) malloc(sizeof(int**) * p);
    for(int i = 0; i < p; i++){
        //allocate 2d matrix sections
        mat3d[i] = allocateMatrix(m, n);
    }
    return mat3d;
}

void freeMatrix3d(int*** mat3d, int m, int p){
    //free the resource
    for(int i = 0; i < p; i++){
        free(mat3d[i]);
    }
    free(mat3d);
}

void readMatrix3d(int*** mat3d, int m, int n, int p){
    char buf[100];
    for(int j = 0; j < n; j++){
        for(int i = 0; i < m; i++){
            for(int k = 0; k < p; k++){
                fgets(buf, sizeof(buf), stdin);
                sscanf(buf, "%d", &(mat3d[k][i][j]));
            }
        }
    }
}

void printMatrix3d(int*** mat3d, int m, int n, int p){
    for(int i = 0; i < p; i++){
        printf("Section %d:\n", i + 1);
        printMatrix(mat3d[i], m, n);
    }
}

int main(int argc, char** argv){
    //reading the size of matrix
    char buf[100];
    int m, n, p;

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &m);

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &n);

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &p);

    //allocate and reading matrix

    int*** mat3d = allocateMatrix3d(m, n, p);
    readMatrix3d(mat3d, m, n, p);

    //print the section
    printMatrix3d(mat3d, m, n, p);

    //free the resources
    freeMatrix3d(mat3d, m, p);
    return 0;
}
