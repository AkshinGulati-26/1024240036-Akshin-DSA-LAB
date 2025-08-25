#include <stdio.h>

int main() {
    int n;
    printf("Enter n (array has numbers 1..n+1 with one missing): ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int total = (n + 1) * (n + 2) / 2;
    for (int i = 0; i < n; i++) total -= arr[i];

    printf("Missing number = %d\n", total);
    return 0;
}