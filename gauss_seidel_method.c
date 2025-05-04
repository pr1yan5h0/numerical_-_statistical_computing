#include <stdio.h>
#include <math.h>

#define SIZE 10
#define EPSILON 0.0001
#define MAX_ITER 100

void gaussSeidel(int n, float a[SIZE][SIZE], float b[SIZE], float x[SIZE]) {
    int i, j, iter = 0;
    float sum, x_old[SIZE];
    
    for (i = 0; i < n; i++)
        x[i] = 0;

    printf("Iter\t");
    for (i = 0; i < n; i++)
        printf("x%d\t\t", i + 1);
    printf("\n");

    while (iter < MAX_ITER) {
        for (i = 0; i < n; i++)
            x_old[i] = x[i];

        for (i = 0; i < n; i++) {
            sum = b[i];
            for (j = 0; j < n; j++) {
                if (j != i)
                    sum -= a[i][j] * x[j];
            }
            x[i] = sum / a[i][i];
        }

        printf("%d\t", iter + 1);
        for (i = 0; i < n; i++)
            printf("%.6f\t", x[i]);
        printf("\n");


        int converged = 1;
        for (i = 0; i < n; i++) {
            if (fabs(x[i] - x_old[i]) > EPSILON) {
                converged = 0;
                break;
            }
        }

        if (converged) break;

        iter++;
    }

    if (iter == MAX_ITER)
        printf("\nDid not converge in %d iterations.\n", MAX_ITER);
    else
        printf("\nConverged in %d iterations.\n", iter + 1);
}

int main() {
    int i, j, n;
    float a[SIZE][SIZE], b[SIZE], x[SIZE];

    printf("Enter number of variables: ");
    scanf("%d", &n);

    printf("Enter coefficients of the matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter constants vector b:\n");
    for (i = 0; i < n; i++) {
        printf("b[%d]: ", i + 1);
        scanf("%f", &b[i]);
    }

    gaussSeidel(n, a, b, x);

    return 0;
}
