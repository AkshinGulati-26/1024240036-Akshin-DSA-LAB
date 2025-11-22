#include <stdio.h>
#define N 10

int q1[N], q2[N], f1 = 0, r1 = -1, f2 = 0, r2 = -1;

void push2(int x) {
    q2[++r2] = x;
    while (f1 <= r1) q2[++r2] = q1[f1++];
    for (int i = 0; i <= r2; i++) q1[i] = q2[i];
    r1 = r2; f1 = 0; r2 = -1; f2 = 0;
}

int pop2() {
    if (f1 > r1) return -1;
    return q1[f1++];
}

int q[N], f = 0, r = -1;

void push1(int x) {
    q[++r] = x;
}

int pop1() {
    int c = r;
    while (c > f) q[++r] = q[f++];
    return q[f++];
}

int main() {
    push2(5);
    push2(9);
    printf("%d\n", pop2());
    push1(3);
    push1(7);
    printf("%d\n", pop1());
}
