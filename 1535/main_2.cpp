#include <iostream>
#include <cstring>

#define max(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

int n;
int l[20], J[20];
int dp[20][101];

int main()
{
    memset(dp, -1, sizeof dp);

    cin >> n;
    int M = 0;
    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 0; i < n; i++) cin >> J[i];
    for (int i = 0 ; i < n ; i++) dp[i][100-l[i]] = J[i],M=max(M,J[i]);

    
    for (int i = 1; i < n; i++){
        for (int j = 100; j > 0; j--){
            dp[i][j] = dp[i-1][j];
            if (j + l[i] <= 100){
                dp[i][j] = max(dp[i][j], dp[i - 1][j + l[i]] + J[i]);
                M = max(M,dp[i][j]);
            }
        }
    }

    cout << M;
}

/*
3
1 21 79
20 30 25


1
1
1

2
50 50
10 5

2 
70 60
60 60

5
10 20 30 40 20
1  10  100 1000 10000

4
0 90 0 79
1 10 100 1000
*/