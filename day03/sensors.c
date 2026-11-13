
#include <stdio.h>

#define COUNT 10

int minimum(int a[], int n) {
    int min = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < min) min = a[i];
    }

    return min;
}

int maximum(int a[], int n) {
    int max = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > max) max = a[i];
    }

    return max;
}

float average(int a[], int n) {
    long sum = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    return (float)sum / n;
}

int main(void) {
    int readings[COUNT];
    int above = 0;

    printf("Enter 10 sensor readings:\n");

    for (int i = 0; i < COUNT; i++) {
        scanf("%d", &readings[i]);
    }

    float avg = average(readings, COUNT);

    for (int i = 0; i < COUNT; i++) {
        if (readings[i] > avg) above++;
    }

    printf("Min: %d\n", minimum(readings, COUNT));
    printf("Max: %d\n", maximum(readings, COUNT));
    printf("Average: %.2f\n", avg);
    printf("Above average: %d\n", above);

    return 0;
}

