
//q5
#include <stdio.h>
int main() {
    int matrix[10][10], rows, cols, i, j, sumRow, sumCol;
    scanf("%d%d", &rows, &cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    for (i = 0; i < rows; i++) {
        sumRow = 0;
        for (j = 0; j < cols; j++) {
            sumRow += matrix[i][j];
        }
        printf("Row %d sum: %d\n", i + 1, sumRow);
    }
    for (j = 0; j < cols; j++) {
        sumCol = 0;
        for (i = 0; i < rows; i++) {
            sumCol += matrix[i][j];
        }
        printf("Col %d sum: %d\n", j + 1, sumCol);
    }
}


