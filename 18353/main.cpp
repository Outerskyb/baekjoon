#include <iostream>
#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int dp[2000];
    int arr[2000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i], dp[i] = 1;
    }

    int M = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (arr[i] < arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        M = max(M, dp[i]);
    }
    cout << n-M;
}