#include <stdio.h>
#include <math.h>
#define EPSILON 0.00001 
#define MAX_ITER 100    

double f(double x) {
    return x * x * x - x - 2; 
}

void secant(double x0, double x1) {
    double x2, f0, f1, f2;
    int iter = 0;
    printf("Iter\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    do {
        f0 = f(x0);
        f1 = f(x1);

        if (fabs(f1 - f0) < EPSILON) {
            printf("Denominator too small. Stopping.\n");
            return;
        }
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        f2 = f(x2);

        printf("%d\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n", iter + 1, x0, x1, x2, f2);

        x0 = x1;
        x1 = x2;
        iter++;

        if (iter > MAX_ITER) {
            printf("Method did not converge within %d iterations.\n", MAX_ITER);
            return;
        }
    } while (fabs(f2) > EPSILON);

    printf("\nRoot is: %.6lf\n", x2);
} 
int main() {
    double x0, x1;

    printf("Enter initial two guesses: ");
    scanf("%lf %lf", &x0, &x1);

    secant(x0, x1);

    return 0;
}
