#include <stdio.h>

int main(void) {
    int reading;

    printf("Enter ADC reading: ");
    scanf("%d", &reading);

    if (reading < 0 || reading > 1023) {
        printf("Invalid reading\n");
    } else {
        printf("Reading: %d\n", reading);
        printf("Voltage: %.2f V\n", reading * 5.0 / 1023);
        printf("Level: %d%%\n", reading * 100 / 1023);
    }

    return 0;
}