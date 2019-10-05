#include<iostream>

using namespace std;

int main() {
    int A, B, C, mul;
    int ary[10] = { 0, };
    scanf("%d %d %d", &A, &B, &C);

    mul = A * B * C;

    while (mul != 0) {
        ary[mul % 10]++;
        mul /= 10;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n", ary[i]);
    }
    
}