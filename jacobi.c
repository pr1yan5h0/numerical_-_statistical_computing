#include <stdio.h>
#include <math.h>

#define SIZE 10
#define EPSILON 0.0001
#define MAX_ITER 100

void jacobi(int n, float a[SIZE][SIZE], float b[SIZE], float x[SIZE]) {
    float x_new[SIZE];
    int i, j, iter = 0;
    float sum;

    for (i = 0; i < n; i++)
        x[i] = 0;

    printf("Iter\t");
    for (i = 0; i < n; i++)
        printf("x%d\t\t", i + 1);
    printf("\n");

    while (iter < MAX_ITER) {
        for (i = 0; i < n; i++) {
            sum = b[i];
            for (j = 0; j < n; j++) {
                if (j != i)
                    sum -= a[i][j] * x[j];
            }
            x_new[i] = sum / a[i][i];
        }

        printf("%d\t", iter + 1);
        for (i = 0; i < n; i++)
            printf("%.6f\t", x_new[i]);
        printf("\n");

        int converged = 1;
        for (i = 0; i < n; i++) {
            if (fabs(x_new[i] - x[i]) > EPSILON)
                converged = 0;
            x[i] = x_new[i];
        }

        if (converged)
            break;

        iter++;
    }

    if (iter == MAX_ITER)
        printf("\nDid not converge within %d iterations.\n", MAX_ITER);
    else
        printf("\nConverged in %d iterations.\n", iter + 1);
}

int main() {
    int i, j, n;
    float a[SIZE][SIZE], b[SIZE], x[SIZE];

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    printf("Enter coefficients of matrix A:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }

    printf("Enter constants vector b:\n");
    for (i = 0; i < n; i++) {
        printf("b[%d]: ", i + 1);
        scanf("%f", &b[i]);
    }

    jacobi(n, a, b, x);

    return 0;
}
