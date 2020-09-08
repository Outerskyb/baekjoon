#include <iostream>
#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int main() {
    int N;
    int cost[300];
    int dp[300][2];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &cost[i]);
    }

    
    dp[0][0] = 0;
    dp[0][1] = cost[0];
    dp[1][0] = cost[0];
    dp[1][1] = cost[0]+ cost[1];

    for (int i = 2; i < N; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = max(dp[i - 2][0] + cost[i - 1], dp[i - 2][1]) + cost[i];
    }

    printf("%d", dp[N - 1][1]);
    
}