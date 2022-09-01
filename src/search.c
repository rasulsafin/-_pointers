#include <stdio.h>
#include <math.h>
#define NMAX 30
/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

int input(int *a, int *n, int *incorrect_input);
double mean(int *a, int n);
double variance(int *a, int n);

int output_result(int *a, int n, double mean_v, double variance_v);

int input(int *a, int *n, int *incorrect_input) {
    if (scanf("%d", n) != 1) {
        printf("n/a");
        *incorrect_input = 1;
        return 0;
    }

    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) == 0) {
            printf("n/a");
            *incorrect_input = 1;
            return 0;
        }
    }

    return 0;
}

double mean(int *a, int n) {
    double sum = 0;

    for (int i = 0; i < n; i++) {
      sum += a[i];
    }

    return sum/(double)n;
}

double variance(int *a, int n) {
    double sum = 0;

    for (int i = 0; i < n; i++) {
        sum += (a[i] - mean(a, n)) * (a[i] - mean(a, n));
    }

    return sum / n;
}

/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

int output_result(int *a, int  n, double mean_v, double variance_v) {
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && a[i] >= mean_v && a[i] <= mean_v + 3 * sqrt(variance_v) && a[i] != 0) {
            printf("%d", a[i]);
            return 0;
        }
    }

    printf("%d", 0);
    return 0;
}


int main() {
    int n, data[NMAX];
    int incorrect_input = 0;
    input(data, &n, &incorrect_input);
    if (incorrect_input == 1) return 0;

    output_result(data, n, mean(data, n), variance(data, n));

    return 0;
}
