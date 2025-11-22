#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertBeginning(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void insertAfterValue(int value, int key) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) temp = temp->next;
    if (temp == NULL) {
        printf("Node %d not found.\n", key);
        return;
    }
    struct Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteBeginning() {
    if (head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void deleteSpecific(int key) {
    if (head == NULL) return;
    if (head->data == key) {
        deleteBeginning();
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) temp = temp->next;
    if (temp->next == NULL) {
        printf("Node %d not found.\n", key);
        return;
    }
    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
}

void search(int key) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Node %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Node %d not found\n", key);
}

void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, key;
    while (1) {
        printf("\n1.Insert Beginning\n2.Insert End\n3.Insert After Value\n4.Delete Beginning\n5.Delete End\n6.Delete Specific\n7.Search\n8.Display\n9.Exit\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: printf("Value: "); scanf("%d", &value); insertBeginning(value); break;
        case 2: printf("Value: "); scanf("%d", &value); insertEnd(value); break;
        case 3: printf("Insert Value & Node after which to insert: "); scanf("%d %d", &value, &key); insertAfterValue(value, key); break;
        case 4: deleteBeginning(); break;
        case 5: deleteEnd(); break;
        case 6: printf("Key: "); scanf("%d", &key); deleteSpecific(key); break;
        case 7: printf("Key: "); scanf("%d", &key); search(key); break;
        case 8: display(); break;
        case 9: exit(0);
        default: printf("Invalid Choice\n");
        }
    }
}
