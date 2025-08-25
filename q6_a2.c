#include <stdio.h>

int main() {
    int r, c;
    printf("Enter rows and cols: ");
    scanf("%d %d", &r, &c);
    int A[r][c], B[r][c], Sum[r][c], Trans[c][r];

    printf("Enter A: ");
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) scanf("%d", &A[i][j]);
    printf("Enter B: ");
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) scanf("%d", &B[i][j]);

    // a. Transpose A
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) Trans[j][i] = A[i][j];
    printf("Transpose of A:\n");
    for (int i = 0; i < c; i++) { for (int j = 0; j < r; j++) printf("%d ", Trans[i][j]); printf("\n"); }

    // b. Addition
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) Sum[i][j] = A[i][j] + B[i][j];
    printf("A + B:\n");
    for (int i = 0; i < r; i++) { for (int j = 0; j < c; j++) printf("%d ", Sum[i][j]); printf("\n"); }

    return 0;
}