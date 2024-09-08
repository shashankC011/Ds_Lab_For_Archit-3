#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 

typedef struct {
    int row;
    int col;
    int value;
} SparseElement;

void fastTranspose(SparseElement input[], int n, SparseElement output[], int *newN) {
    int rowSize[MAX_SIZE] = {0};
    int startingPos[MAX_SIZE] = {0};
    
    // number of elements in each column of the original matrix
    for (int i = 0; i < n; i++) {
        rowSize[input[i].col]++;
    }

    //starting position of each column in the transposed matrix
    startingPos[0] = 0;
    for (int i = 1; i < MAX_SIZE; i++) {
        startingPos[i] = startingPos[i - 1] + rowSize[i - 1];
    }

    // Placing elements in the transposed matrix
    for (int i = 0; i < n; i++) {
        int pos = startingPos[input[i].col]++;
        output[pos].row = input[i].col;
        output[pos].col = input[i].row;
        output[pos].value = input[i].value;
    }

    *newN = n; // Number of non-zero elements in the transposed matrix is the same
}

void printSparseMatrix(SparseElement arr[], int n) {
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", arr[i].row, arr[i].col, arr[i].value);
    }
}


int main() {
    SparseElement matrix[MAX_SIZE] = {
        {0, 1, 5},
        {1, 0, 8},
        {2, 2, 7},
        {2, 1, 9}
    };
    SparseElement transposed[MAX_SIZE];
    int n = 4; // Number of non-zero elements in the original matrix
    int newN;

    printf("Original Sparse Matrix:\n");
    printSparseMatrix(matrix, n);

    fastTranspose(matrix, n, transposed, &newN);

    printf("\nTransposed Sparse Matrix:\n");
    printSparseMatrix(transposed, newN);

    return 0;
}
