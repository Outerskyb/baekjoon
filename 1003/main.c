#include<stdio.h>
int zeros;
int ones;
int fibonacci(int n) {
    if (n == 0) {
        zeros++;
        return 0;
    }
    else if (n == 1) {
        ones++;
        return 1;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        zeros = ones = 0;
        int N;
        scanf("%d", &N);
        fibonacci(N);
        printf("%d %d\n", zeros, ones);
    }
}