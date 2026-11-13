
#include <stdio.h>

int main(void) {
    int rows;

    printf("Rows (1-9): ");
    scanf("%d", &rows);

    if (rows < 1 || rows > 9) {
        printf("Invalid rows\n");
        return 0;
    }

    for (int r = 1; r <= rows; r++) {
        for (int c = 1; c <= r; c++) {
            printf("%d", c);
            if (c < r) printf(" ");
        }
        printf("\n");
    }

    return 0;
}

