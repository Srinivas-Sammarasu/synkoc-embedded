
#include <stdio.h>

void printBanner(void);
int readSensor(void);
void printReading(int value);
float toVolts(int raw);

int main(void) {
    int raw;

    printf("Raw ADC value: ");
    scanf("%d", &raw);

    printBanner();
    printf("Sensor says: %d\n", readSensor());
    printReading(raw);
    printf("Volts: %.2f\n", toVolts(raw));

    return 0;
}

void printBanner(void) {
    printf("=== SYNKOC Sensor Tools ===\n");
}

int readSensor(void) {
    return 512;
}

void printReading(int value) {
    printf("Reading: %d\n", value);
}

float toVolts(int raw) {
    return raw * 5.0 / 1023;
}
