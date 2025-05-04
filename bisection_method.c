#include <stdio.h>
#include <math.h>

#define EPSILON 0.00001 

double f(double x) {
    return x*x*x - x - 2;  
}

void bisection(double a, double b) {
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval. f(a) and f(b) must have opposite signs.\n");
        return;
    }

    double c;
    int iteration = 1;

    printf("Iter\ta\t\tb\t\tc\t\tf(c)\n");

    while ((b - a) >= EPSILON) {
        c = (a + b) / 2;

        printf("%d\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n", iteration, a, b, c, f(c));

        if (fabs(f(c)) < EPSILON)
            break;

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        iteration++;
    }

    printf("\nThe root is: %.6lf\n", c);
}

int main() {
    double a, b;

    printf("Enter the initial interval (a and b): ");
    scanf("%lf %lf", &a, &b);

    bisection(a, b);

    return 0;
}
