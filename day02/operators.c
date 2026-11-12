#include <stdio.h>

int main(void) {
    int a, b;

    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    printf("Sum: %d\n", a + b);
    printf("Difference: %d\n", a - b);
    printf("Product: %d\n", a * b);

    if (b == 0) {
        printf("Cannot divide by zero\n");
    } else {
        printf("Quotient: %d\n", a / b);
        printf("Remainder: %d\n", a % b);
        printf("Exact: %.2f\n", (float)a / b);
    }

    printf("a > b: %d\n", a > b);
    printf("a == b: %d\n", a == b);

    a += 5;
    printf("After a += 5: %d\n", a);

    return 0;
}