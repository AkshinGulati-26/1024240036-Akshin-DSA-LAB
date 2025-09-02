#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int total = (n + 1) * (n + 2) / 2;
    for (int i = 0; i < n; i++) total -= arr[i];

    printf("Missing number = %d\n", total);
    return 0;
}
