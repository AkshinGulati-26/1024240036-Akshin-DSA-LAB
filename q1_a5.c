#include <stdio.h>
#define N 5
int q[N], f = 0, r = -1;

void enqueue(int x) {
    if (r == N - 1) printf("Full\n");
    else q[++r] = x;
}

void dequeue() {
    if (f > r) printf("Empty\n");
    else f++;
}

void display() {
    if (f > r) printf("Empty\n");
    else {
        for (int i = f; i <= r; i++) printf("%d ", q[i]);
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    dequeue();
    display();
}
