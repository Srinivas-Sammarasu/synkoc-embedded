#include <stdio.h>

#define CURRENT_THRESHOLD 700

int main(void) {
    int reading;

    printf("Project: MotorGuard - Intelligent Motor Health Monitoring and Protection System\n");

    printf("Pins:\n");
    printf("- Vibration sensor (simulated): A0\n");
    printf("- Temperature sensor (simulated): A1\n");
    printf("- Current input (potentiometer): A2\n");
    printf("- Green LED (normal): 6\n");
    printf("- Red LED (fault): 7\n");
    printf("- Buzzer: 8\n");

    printf("Enter simulated current reading: ");
    scanf("%d", &reading);

    printf("Reading: %d\n", reading);

    // At exactly the threshold (700), a fault is detected.
    if (reading >= CURRENT_THRESHOLD) {
        printf("Decision: ON\n");
    } else {
        printf("Decision: OFF\n");
    }

    return 0;
}