 #include <stdio.h>
#include <stdlib.h>

void add(int **A, int **B, int **C, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int **A, int **B, int **C, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int **A, int **B, int **C, int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;
    int **A11 = (int **)malloc(newSize * sizeof(int *));
    int **A12 = (int **)malloc(newSize * sizeof(int *));
    int **A21 = (int **)malloc(newSize * sizeof(int *));
    int **A22 = (int **)malloc(newSize * sizeof(int *));
    int **B11 = (int **)malloc(newSize * sizeof(int *));
    int **B12 = (int **)malloc(newSize * sizeof(int *));
    int **B21 = (int **)malloc(newSize * sizeof(int *));
    int **B22 = (int **)malloc(newSize * sizeof(int *));
    int **C11 = (int **)malloc(newSize * sizeof(int *));
    int **C12 = (int **)malloc(newSize * sizeof(int *));
    int **C21 = (int **)malloc(newSize * sizeof(int *));
    int **C22 = (int **)malloc(newSize * sizeof(int *));
    int **M1 = (int **)malloc(newSize * sizeof(int *));
    int **M2 = (int **)malloc(newSize * sizeof(int *));
    int **M3 = (int **)malloc(newSize * sizeof(int *));
    int **M4 = (int **)malloc(newSize * sizeof(int *));
    int **M5 = (int **)malloc(newSize * sizeof(int *));
    int **M6 = (int **)malloc(newSize * sizeof(int *));
    int **M7 = (int **)malloc(newSize * sizeof(int *));
    int **tempA = (int **)malloc(newSize * sizeof(int *));
    int **tempB = (int **)malloc(newSize * sizeof(int *));

    for (int i = 0; i < newSize; i++) {
        A11[i] = (int *)malloc(newSize * sizeof(int));
        A12[i] = (int *)malloc(newSize * sizeof(int));
        A21[i] = (int *)malloc(newSize * sizeof(int));
        A22[i] = (int *)malloc(newSize * sizeof(int));
        B11[i] = (int *)malloc(newSize * sizeof(int));
        B12[i] = (int *)malloc(newSize * sizeof(int));
        B21[i] = (int *)malloc(newSize * sizeof(int));
        B22[i] = (int *)malloc(newSize * sizeof(int));
        C11[i] = (int *)malloc(newSize * sizeof(int));
        C12[i] = (int *)malloc(newSize * sizeof(int));
        C21[i] = (int *)malloc(newSize * sizeof(int));
        C22[i] = (int *)malloc(newSize * sizeof(int));
        M1[i] = (int *)malloc(newSize * sizeof(int));
        M2[i] = (int *)malloc(newSize * sizeof(int));
        M3[i] = (int *)malloc(newSize * sizeof(int));
        M4[i] = (int *)malloc(newSize * sizeof(int));
        M5[i] = (int *)malloc(newSize * sizeof(int));
        M6[i] = (int *)malloc(newSize * sizeof(int));
        M7[i] = (int *)malloc(newSize * sizeof(int));
        tempA[i] = (int *)malloc(newSize * sizeof(int));
        tempB[i] = (int *)malloc(newSize * sizeof(int));
    }

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    add(A11, A22, tempA, newSize);
    add(B11, B22, tempB, newSize);
    strassen(tempA, tempB, M1, newSize);

    add(A21, A22, tempA, newSize);
    strassen(tempA, B11, M2, newSize);

    subtract(B12, B22, tempB, newSize);
    strassen(A11, tempB, M3, newSize);

    subtract(B21, B11, tempB, newSize);
    strassen(A22, tempB, M4, newSize);

    add(A11, A12, tempA, newSize);
    strassen(tempA, B22, M5, newSize);

    subtract(A21, A11, tempA, newSize);
    add(B11, B12, tempB, newSize);
    strassen(tempA, tempB, M6, newSize);

    subtract(A12, A22, tempA, newSize);
    add(B21, B22, tempB, newSize);
    strassen(tempA, tempB, M7, newSize);

    add(M1, M4, tempA, newSize);
    subtract(tempA, M5, tempB, newSize);
    add(tempB, M7, C11, newSize);

    add(M3, M5, C12, newSize);
    add(M2, M4, C21, newSize);

    add(M1, M3, tempA, newSize);
    subtract(tempA, M2, tempB, newSize);
    add(tempB, M6, C22, newSize);

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    for (int i = 0; i < newSize; i++) {
        free(A11[i]);
        free(A12[i]);
        free(A21[i]);
        free(A22[i]);
        free(B11[i]);
        free(B12[i]);
        free(B21[i]);
        free(B22[i]);
        free(C11[i]);
        free(C12[i]);
        free(C21[i]);
        free(C22[i]);
        free(M1[i]);
        free(M2[i]);
        free(M3[i]);
        free(M4[i]);
        free(M5[i]);
        free(M6[i]);
        free(M7[i]);
        free(tempA[i]);
        free(tempB[i]);
    }

    free(A11);
    free(A12);
    free(A21);
    free(A22);
    free(B11);
    free(B12);
    free(B21);
    free(B22);
    free(C11);
    free(C12);
    free(C21);
    free(C22);
    free(M1);
    free(M2);
    free(M3);
    free(M4);
    free(M5);
    free(M6);
    free(M7);
    free(tempA);
    free(tempB);
}

int main() {
    int size;
    printf("Enter the size of the matrices (must be a power of 2): ");
    scanf("%d", &size);

    int **A = (int **)malloc(size * sizeof(int *));
    int **B = (int **)malloc(size * sizeof(int *));
    int **C = (int **)malloc(size * sizeof(int *));

    for (int i = 0; i < size; i++) {
        A[i] = (int *)malloc(size * sizeof(int));
        B[i] = (int *)malloc(size * sizeof(int));
        C[i] = (int *)malloc(size * sizeof(int));
    }

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter elements of matrix B:\n");
    // Input for matrix B
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Perform Strassen matrix multiplication
    strassen(A, B, C, size);

    // Output the result matrix C
    printf("Result matrix C (A * B):\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    for (int i = 0; i < size; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }

    free(A);
    free(B);
    free(C);

    return 0;
}