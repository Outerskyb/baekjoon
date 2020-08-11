#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int coin[2000];
    int dp[2000][2000];
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> coin[i];
    }
}