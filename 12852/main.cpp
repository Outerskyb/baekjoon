#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int dp[1000001];
int trace[1000001];

int N;

int func(int num) {
    if (dp[num] != 2139062143) return dp[num];
    if (num == 1) return 0;

    if (num % 3 == 0) {
        int temp = func(num / 3);
        if (dp[num] > temp + 1) {
            dp[num] = temp + 1;
            trace[num] = num/3;
        }
    }

    if (num % 2 == 0) {
        int temp = func(num / 2);
        if (dp[num] > temp + 1) {
            dp[num] = temp + 1;
            trace[num] = num/2;
        }
    }
    int temp = func(num - 1);
    if (dp[num] > temp + 1) {
        dp[num] = temp+1;
        trace[num] = num-1;
    }
    return dp[num];
}

int main()
{
    memset(dp, 127, sizeof dp);

    cin >> N;
    cout << func(N)<<'\n';

    int tracer = N;
    while (tracer != 1) {
        cout << tracer << ' ';
        tracer = trace[tracer];
    }
    cout << 1;
    return 0;
}