#include <iostream>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int arr[1000];
    int dp[1000];
    int sum[1000];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i], sum[i] = arr[i];

    int M = sum[0];
    for (int i = 1; i < n; i++) {
        
        for (int j = 0; j <= i; j++) {
            if (arr[i] > arr[j] ) {
                dp[i] = max(dp[i],dp[j] + 1);
                sum[i] = max(sum[i], sum[j] + arr[i]);
                M = max(M, sum[i]);
            }
        }
    }

    cout << M;


}