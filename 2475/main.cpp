#include<iostream>

int main() {
    int a=0,b;
    for (int c = 0; c < 5; c++) {
        scanf("%d", &b);
        a += b*b;
    }
    printf("%d", a % 10);
}