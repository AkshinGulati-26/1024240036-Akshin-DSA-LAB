//q1
#include <stdio.h>
int main() {
    int numbers[100], count = 0, choice, position, value, i, key, found;
    while (1) {
        printf("1 Create  2 Display  3 Insert  4 Delete  5 Search  6 Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter number of elements: ");
            scanf("%d", &count);
            for (i = 0; i < count; i++) scanf("%d", &numbers[i]);
        } else if (choice == 2) {
            for (i = 0; i < count; i++) printf("%d ", numbers[i]);
        
        } else if (choice == 3) {
            printf("Enter position and value: ");
            scanf("%d%d", &position, &value);
            for (i = count; i >= position; i--) {
            numbers[i] = numbers[i - 1];
            numbers[position - 1] = value;
            count++;
            }
        } else if (choice == 4) {
            printf("Enter position: ");
            scanf("%d", &position);
            for (i = position - 1; i < count - 1; i++) {
                numbers[i] = numbers[i + 1];
            count--;
            }
        } else if (choice == 5) {
            printf("Enter value: ");
            scanf("%d", &key);
            found = 0;
            for (i = 0; i < count; i++) {
                if (numbers[i] == key) {
                    printf("Found at position %d\n", i + 1);
                    found = 1;
                    break;
                }
            }
            if (!found) printf("Not found\n");
        } else if (choice == 6) break;
    }
}

