#include<iostream>
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;

int main() {
    int a, b, c, d, e, f;
    scanf("%d", &a);
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    printf("%d", MAX(MAX(a, a - b + c), a - b + c - d + e));
}