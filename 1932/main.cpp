#include<iostream>
#include<cstdlib>
#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int main()
{
    int N;
    int max = 0;
    int** triangle;
    int** dp;

    scanf("%d", &N);

    triangle = (int**)malloc(sizeof(int*) * N);
    dp = (int**)malloc(sizeof(int*) * N);

    for (int i = 0; i < N; i++)
    {
        triangle[i] = (int*)malloc(sizeof(int) * N);
        dp[i] = (int*)malloc(sizeof(int)*N);

        for (int j = 0; j < i + 1; j++)
        {
            scanf("%d", &triangle[i][j]);
        }
    }

    dp[0][0] = triangle[0][0];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            }
            else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (dp[N - 1][i] > max) {
            max = dp[N - 1][i];
        }
    }
    printf("%d", max);
}