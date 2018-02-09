/*
    JTSK-320111
    p3.c
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

void readMatrix(int** mat, int m, int n){
    char buf[100];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            //reading the input
            fgets(buf, sizeof(buf), stdin);
            sscanf(buf, "%d", &(mat[i][j]));
        }
    }
}

int** matMul(int** mat1, int** mat2, int m, int n, int p){
    //implement the algorithm

    //allocate matrix
    int** result = allocateMatrix(m, p);
    for(int i = 0; i < m; i++){
        for(int k = 0; k < p; k++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                sum += mat1[i][j] * mat2[j][k];
            }
            result[i][k] = sum;
        }
    }
    return result;
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
    
    int** m1 = allocateMatrix(m, n);
    int** m2 = allocateMatrix(n, p);
    readMatrix(m1, m, n);
    readMatrix(m2, n, p);

    //multipy matrix
    int** m3 = matMul(m1, m2, m, n, p);

    //print the result
    printf("Matrix A:\n");
    printMatrix(m1, m, n);
    printf("Matrix B:\n");
    printMatrix(m2, n, p);
    printf("The multiplication result AxB:\n");
    printMatrix(m3, m, p);

    //free resources
    freeMatrix(m1, m);
    freeMatrix(m2, n);
    freeMatrix(m3, m);

    return 0;
}

