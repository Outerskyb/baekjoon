#include <iostream>
#include <cstring>
#include <stack>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int N;
int M;
int nums[300];
int psum[301];
int dp[300][300];

int sum(int left, int right) {
    return psum[right+1] - psum[left];//둘다 포함
}

int func(int left, int groups) 
{
    if (dp[left][groups] != -1) return dp[left][groups];

    dp[left][groups] = 987654321;//임의의 큰값입니당

    if (groups == 1) {
        dp[left][groups] = sum(left, N-1);
        return dp[left][groups];
    }
    
    for (int mid = left; mid < N-1; mid++) 
    {
        if (sum(left, mid) > dp[left][groups]) break;
        int M = max(func(mid + 1,  groups - 1), sum(left, mid));
        if (M < dp[left][groups]) {
            dp[left][groups] = M;
        }
    }
    return dp[left][groups];
}

void tracer(int left,  int groups) 
{
    if (groups == 1) {
        cout << (N-1) - left + 1 << ' ';
        return;
    }
    for (int mid = left; mid < N-1; mid++)
    {
        if (sum(left, mid) == dp[left][groups]
            || dp[mid+1][groups-1] == dp[left][groups]) {
            cout << mid - left + 1 << ' ';
            tracer(mid + 1,  groups - 1);
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof dp);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        psum[i + 1] = psum[i] + nums[i];
    }

    cout << func(0, M)<<'\n';
    tracer(0,  M);
}