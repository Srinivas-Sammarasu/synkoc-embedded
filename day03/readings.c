
#include <stdio.h>

#define CURRENT_THRESHOLD 700
#define MAX_READINGS 50

float averageReadings(int r[], int n) {
    long sum = 0;

    for (int i = 0; i < n; i++) {
        sum += r[i];
    }

    return (float)sum / n;
}

int countAbove(int r[], int n, int threshold) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (r[i] > threshold) count++;
    }

    return count;
}

int main(void) {
    int n;
    int readings[MAX_READINGS];

    printf("Number of readings (1-50): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_READINGS) {
        printf("Invalid count\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &readings[i]);
    }

    float avg = averageReadings(readings, n);

    printf("Average: %.2f\n", avg);
    printf("Above threshold: %d\n",
           countAbove(readings, n, CURRENT_THRESHOLD));

    if (avg >= CURRENT_THRESHOLD) {
        printf("Decision: ON\n");
    } else {
        printf("Decision: OFF\n");
    }

    return 0;
}

