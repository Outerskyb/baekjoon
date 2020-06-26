#include <iostream>
#include <cstring>
#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int main()
{
    int c, n;
    cin >> c >> n;
    int p[20], m[20];
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> m[i];
    }
    int dp[1000000] = { 0, };
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < n; j++) {
            if(i-p[j]>=0)
                dp[i] = max(dp[i], dp[i - p[j]] + m[j]);
        }
    }
    
}