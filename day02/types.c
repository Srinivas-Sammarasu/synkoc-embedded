#include <stdio.h>

#define MAX_READING 1023

int main(void) {
    char device[] = "SmartFan";
    int pin = 9;
    float supply = 4.95;
    double temperature = 31.5;
    char mode = 'A';

    printf("Device: %s\n", device);
    printf("Pin: %d\n", pin);
    printf("Supply: %.2f V\n", supply);
    printf("Temperature: %.1f C\n", temperature);
    printf("Mode: %c\n", mode);
    printf("Max reading: %d\n", MAX_READING);

    return 0;
}