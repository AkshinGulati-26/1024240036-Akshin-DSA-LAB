//q2
#include <stdio.h>
int main() {
    int numbers[100], count, i, j, k;
    scanf("%d", &count);
    for (i = 0; i < count; i++) scanf("%d", &numbers[i]);
    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count;) {
            if (numbers[i] == numbers[j]) {
                for (k = j; k < count - 1; k++) numbers[k] = numbers[k + 1];
                count--;
            } else j++;
        }
    }
    for (i = 0; i < count; i++) printf("%d ", numbers[i]);
}