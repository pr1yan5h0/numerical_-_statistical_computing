#include <stdio.h>
#include <math.h>

#define SIZE 10

void gaussElimination(int n, float a[SIZE][SIZE], float b[SIZE]) {
    int i, j, k;
    float factor;

    for (k = 0; k < n - 1; k++) {
        for (i = k + 1; i < n; i++) {
            if (a[k][k] == 0) {
                printf("Mathematical Error: Division by zero.\n");
                return;
            }
            factor = a[i][k] / a[k][k];
            for (j = k; j < n; j++) {
                a[i][j] -= factor * a[k][j];
            }
            b[i] -= factor * b[k];
        }
    }

    float x[SIZE];
    for (i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.4f\n", i + 1, x[i]);
    }
}

int main() {
    int i, j, n;
    float a[SIZE][SIZE], b[SIZE];

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    printf("Enter the coefficients of the augmented matrix (A|b):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
        printf("b[%d]: ", i + 1);
        scanf("%f", &b[i]);
    }

    gaussElimination(n, a, b);

    return 0;
}
