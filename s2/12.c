#include <stdio.h>
#define MAX 100

void assign(int A[MAX][MAX], int B[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = B[i][j];
        }
    }
}

void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int m = 0; m < n; m++) {
                C[i][j] += A[i][m] * B[m][j];
            }
        }
    }
}

void power(int A[MAX][MAX], int C[MAX][MAX], int n, int k) {
    int B[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) C[i][j] = 1;
            else C[i][j] = 0;
        }
    }
    for (int i = 0; i < k; i++) {
        multiply(C, A, B, n);
        assign(C, B, n);
    }
}

int main() {
    int n, k;
    int A[MAX][MAX], C[MAX][MAX];
    scanf("%i %i", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%i", &A[i][j]);
        }
    }
    power(A, C, n, k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%i ", C[i][j]);
        }
        printf("\n");
    }
}
