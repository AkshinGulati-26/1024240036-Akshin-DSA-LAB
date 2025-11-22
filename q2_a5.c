#include <stdio.h>
#define N 5
int q[N], f = -1, r = -1;

void enqueue(int x) {
    if ((r + 1) % N == f) printf("Full\n");
    else {
        if (f == -1) f = 0;
        r = (r + 1) % N;
        q[r] = x;
    }
}

void dequeue() {
    if (f == -1) printf("Empty\n");
    else if (f == r) f = r = -1;
    else f = (f + 1) % N;
}

void display() {
    if (f == -1) printf("Empty\n");
    else {
        int i = f;
        while (1) {
            printf("%d ", q[i]);
            if (i == r) break;
            i = (i + 1) % N;
        }
        printf("\n");
    }
}

int main() {
    enqueue(4);
    enqueue(7);
    enqueue(11);
    display();
}
