#include <stdio.h>

int main() {
    int n;
    printf("Enter size of matrix: ");
    scanf("%d", &n);
    int mat[n][n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    int diag[n];
    for (int i = 0; i < n; i++) diag[i] = mat[i][i];

    printf("Diagonal elements stored: ");
    for (int i = 0; i < n; i++) printf("%d ", diag[i]);
    return 0;
}
