
#include <stdio.h>

void readMatrix(int m[3][3]) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            scanf("%d", &m[r][c]);
        }
    }
}

void printMatrix(int m[3][3]) {
    for (int r = 0; r < 3; r++) {
        printf("%d %d %d\n", m[r][0], m[r][1], m[r][2]);
    }
}

int main(void) {
    int a[3][3], b[3][3];
    int sum[3][3], product[3][3];

    printf("Enter matrix A, then matrix B:\n");
    readMatrix(a);
    readMatrix(b);

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            sum[r][c] = a[r][c] + b[r][c];

            product[r][c] = 0;
            for (int k = 0; k < 3; k++) {
                product[r][c] += a[r][k] * b[k][c];
            }
        }
    }

    printf("Sum:\n");
    printMatrix(sum);

    printf("Product:\n");
    printMatrix(product);

    return 0;
}
