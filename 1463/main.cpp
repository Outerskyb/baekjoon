#include <iostream>
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;

int N;
int dp[100000][3];

int main() {
    int count = 1;

    scanf("%d", &N);
    dp[1][0] = (N % 3 == 0) ? N / 3 : 1234567;
    dp[1][1] = (N % 2 == 0) ? N / 2 : 1234567;
    dp[1][2] = N - 1;

    while (dp[count][0] != 1 && dp[count][1] != 1 && dp[count][2] != 1 ) {
        count++;
        dp[count][0] = (dp[count - 1][0] % 3 == 0) ? 
            (dp[count - 1][1] % 3 == 0) ?
                (dp[count - 1][2] % 3 == 0) ?
                    min(dp[count - 1][0], min(dp[count - 1][1], dp[count - 1][2])) / 3 : min(dp[count - 1][0], dp[count - 1][1]) / 3
            : (dp[count - 1][2] % 3 == 0) 
                    ? min(dp[count - 1][0], dp[count - 1][2]) / 3 : dp[count - 1][0] / 3
        : (dp[count - 1][1] % 3 == 0) 
            ? (dp[count - 1][2] % 3 == 0) 
                ? min(dp[count - 1][1], dp[count - 1][2]) / 3 : dp[count - 1][1] / 3 
            : (dp[count - 1][2] % 3 == 0) ? dp[count - 1][2] / 3 : 1234567;
        
        dp[count][1] = (dp[count - 1][0] % 2 == 0) ?
            (dp[count - 1][1] % 2 == 0) ?
            (dp[count - 1][2] % 2 == 0) ?
            min(dp[count - 1][0], min(dp[count - 1][1], dp[count - 1][2])) / 2 : min(dp[count - 1][0], dp[count - 1][1]) / 2
            : (dp[count - 1][2] % 2 == 0)
            ? min(dp[count - 1][0], dp[count - 1][2]) / 2 : dp[count - 1][0] / 2
            : (dp[count - 1][1] % 2 == 0)
            ? (dp[count - 1][2] % 2 == 0)
            ? min(dp[count - 1][1], dp[count - 1][2]) / 2 : dp[count - 1][1] / 2
            : (dp[count - 1][2] % 2 == 0) ? dp[count - 1][2] / 2 : 1234567;
        dp[count][2] = min(dp[count - 1][0], min(dp[count - 1][1], dp[count - 1][2])) - 1;
    }

    printf("%d", count);
}