#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int *incorrect_input);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    int incorrect_input = 0;
    input(data, &n, &incorrect_input);
    if (incorrect_input == 1) {
        return 0;
    }
    squaring(data, n);
    output(data, n);
    return 0;
}

int input(int *a, int *n, int *incorrect_input) {
    if (scanf("%d", n) == 0) {
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
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] *= a[i];
    }
}


