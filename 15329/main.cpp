#include "bits/stdc++.h"

using namespace std;

uint64_t dp[101];

int main(){
    int l,k;
    cin >> l >> k;
    
    dp[1] = 1;
    dp[2] = k==2;
    dp[3] = 1+k==3;
    for(int i = 0 ; i < l ; i++){

    }
}