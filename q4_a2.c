#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);

    // a
    strcat(s1, s2);
    printf("Concatenated: %s\n", s1);

    //b
    int n = strlen(s1);
    for (int i = 0; i < n / 2; i++) {
        char t = s1[i]; 
        s1[i] = s1[n - i - 1]; 
        s1[n - i - 1] = t;
    }
    printf("Reversed: %s\n", s1);

    // c
    char temp[100];
    int j = 0;
    for (int i = 0; s1[i]; i++) {
        if (strchr("aeiouAEIOU", s1[i]) == NULL) temp[j++] = s1[i];
    }
    printf("Without vowels: %s\n", temp);

    return 0;
}
