#include <stdio.h>
#include <math.h>

#define EPSILON 0.00001
#define MAX_ITER 100

double f(double x) {
    return x*x*x - x - 2;
}

double df(double x) {
    return 3*x*x - 1;
}

void newtonRaphson(double x0) {
    double x1;
    int iter = 1;

    printf("Iter\tx0\t\tf(x0)\t\tx1\n");

    while (iter <= MAX_ITER) {
        double f0 = f(x0);
        double df0 = df(x0);

        if (fabs(df0) < 1e-8) {
            printf("Derivative too small. Division by zero risk.\n");
            return;
        }

        x1 = x0 - f0 / df0;

        printf("%d\t%.6lf\t%.6lf\t%.6lf\n", iter, x0, f0, x1);

        if (fabs(x1 - x0) < EPSILON) {
            printf("\nRoot found: %.6lf\n", x1);
            return;
        }

        x0 = x1;
        iter++;
    }

    printf("\nDid not converge within %d iterations.\n", MAX_ITER);
}

int main() {
    double x0;

    printf("Enter initial guess: ");
    scanf("%lf", &x0);

    newtonRaphson(x0);

    return 0;
}
