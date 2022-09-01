#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int *incorrect_input);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

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

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int min(int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] < min) min = a[i];
    }
    return min;
}

int max(int *a, int n) {
    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
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
    // printf("%f", sum);

    return sum / n;
}

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
                       printf("%d ", max_v);
                       printf("%d ", min_v);
                       printf("%.6f ", mean_v);
                       printf("%.6f", variance_v);
                   }


int main() {
    int n, data[NMAX];
    int incorrect_input = 0;
    input(data, &n, &incorrect_input);
    if (incorrect_input == 1) return 0;
    output(data, n);
    output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));

    return 0;
}
