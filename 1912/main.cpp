#include <iostream>
#define max(a,b) (((a)>(b))?(a):(b))


using namespace std;

int input[100001];
int dp[100001];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }
    dp[0] = input[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + input[i], input[i]);
        printf("%d\n", dp[i]);
    }
    int Max;
    Max = dp[0];
    for (int i = 0; i < n; i++) {
        if (dp[i] > Max) Max = dp[i];
    }
    printf("%d", Max);
}