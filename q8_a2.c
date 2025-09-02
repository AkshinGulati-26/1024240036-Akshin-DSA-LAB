#include <stdio.h>

int main() {
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int count = 0;
    for (int i = 0; i < n; i++) {
        int seen=0;
        for (int j = 0; j < i; j++){
            if (arr[i] == arr[j]) {
             seen = 1; 
             break; 
            }
         if (!seen) count++;
    }

    printf("Distinct count = %d\n", count);
    return 0;
}
