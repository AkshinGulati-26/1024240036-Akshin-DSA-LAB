#include <stdio.h>
int main() {
    int a[6] = {4,7,11,20,5,9};
    int t[3], k = 0, i;
    for (i = 0; i < 3; i++) t[k++] = a[i];
    k = 0;
    int p = 3;
    for (i = 0; i < 6; i++) {
        if (i % 2 == 0) a[i] = t[k++];
        else a[i] = a[p++];
    }
    for (i = 0; i < 6; i++) printf("%d ", a[i]);
}
