
#include <stdio.h>

int main(void) {
    int n;

    printf("N (1-20): ");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Invalid N\n");
        return 0;
    }

    printf("for:");
    for (int i = 1; i <= n; i++)
        printf(" %d", i);
    printf("\n");

    printf("while:");
    int k = n;
    while (k >= 1) {
        printf(" %d", k);
        k--;
    }
    printf("\n");

    int sum = 0, j = 1;
    do {
        sum += j;
        j++;
    } while (j <= n);

    printf("do-while sum: %d\n", sum);

    return 0;
}
