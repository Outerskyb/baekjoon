#include<iostream>

int main() {
    int N;
    scanf("%d", &N);
    int dp[100000] = { 3,7, };
    for (int i = 2; i < 100000; i++) {
        dp[i] = (dp[i - 1]%9901) * 2 + dp[i - 2]%9901;

    }
    printf("%d", dp[N-1]%9901);
}