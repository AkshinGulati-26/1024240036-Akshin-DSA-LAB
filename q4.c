//q4#
#include <stdio.h>

void reverseArray() {
    int numbers[100], count, start, end, temp;
    scanf("%d", &count);
    for (start = 0; start < count; start++) scanf("%d", &numbers[start]);
    start = 0; end = count - 1;
    while (start < end) {
        temp = numbers[start];
        numbers[start] = numbers[end];
        numbers[end] = temp;
        start++;
        end--;
    }
    for (start = 0; start < count; start++) printf("%d ", numbers[start]);
    printf("\n");
}
void multiplyMatrices() {
    int a[10][10], b[10][10], result[10][10];
    int rowsA, colsA, rowsB, colsB, i, j, k;
    scanf("%d%d", &rowsA, &colsA);
    scanf("%d%d", &rowsB, &colsB);
    if (colsA != rowsB) return;
    for (i = 0; i < rowsA; i++) for (j = 0; j < colsA; j++) scanf("%d", &a[i][j]);
    for (i = 0; i < rowsB; i++) for (j = 0; j < colsB; j++) scanf("%d", &b[i][j]);
    for (i = 0; i < rowsA; i++) for (j = 0; j < colsB; j++) {
        result[i][j] = 0;
        for (k = 0; k < colsA; k++) result[i][j] += a[i][k] * b[k][j];
    }
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsB; j++) printf("%d ", result[i][j]);
        printf("\n");
    }
}

void transposeMatrix() {
    int matrix[10][10], transpose[10][10];
    int rows, cols, i, j;
    scanf("%d%d", &rows, &cols);
    for (i = 0; i < rows; i++) for (j = 0; j < cols; j++) scanf("%d", &matrix[i][j]);
    for (i = 0; i < rows; i++) for (j = 0; j < cols; j++) transpose[j][i] = matrix[i][j];
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) printf("%d ", transpose[i][j]);
        printf("\n");
    }
}

int main() {
    int choice;
    scanf("%d", &choice);
    if (choice == 1) reverseArray();
    else if (choice == 2) multiplyMatrices();
    else if (choice == 3) transposeMatrix();
}