#include <stdio.h>
#include <math.h>

#define EPSILON 0.00001
#define MAX_ITER 100

double f(double x) {
    return x*x*x - x - 2; 
}

void regulaFalsi(double a, double b) {
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval. f(a) and f(b) must have opposite signs.\n");
        return;
    }

    double c = a;
    int iteration = 1;

    printf("Iter\ta\t\tb\t\tc\t\tf(c)\n");

    while (iteration <= MAX_ITER) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        printf("%d\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n", iteration, a, b, c, f(c));

        if (fabs(f(c)) < EPSILON) {
            printf("\nRoot found: %.6lf\n", c);
            return;
        }

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        iteration++;
    }

    printf("\nMethod did not converge within %d iterations.\n", MAX_ITER);
}

int main() {
    double a, b;

    printf("Enter initial guesses (a and b): ");
    scanf("%lf %lf", &a, &b);

    regulaFalsi(a, b);

    return 0;
}
