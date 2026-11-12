#include <stdio.h>

int main(void) {
    int temp, mode;

    printf("Temperature: ");
    scanf("%d", &temp);

    printf("Mode (1-3): ");
    scanf("%d", &mode);

    if (temp < 25) {
        printf("Fan: OFF\n");
    } else if (temp < 30) {
        printf("Fan: LOW\n");
    } else if (temp < 35) {
        printf("Fan: MEDIUM\n");
    } else {
        printf("Fan: HIGH\n");
    }

    switch (mode) {
        case 1: printf("Mode: Auto\n"); break;
        case 2: printf("Mode: Manual\n"); break;
        case 3: printf("Mode: Sleep\n"); break;
        default: printf("Mode: Invalid\n");
    }

    if (temp >= 40 && mode == 1) {
        printf("ALERT: Overheat\n");
    }

    return 0;
}