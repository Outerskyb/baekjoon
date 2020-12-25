#include "bits/stdc++.h"
#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int n;
vector<pair<int,int>> vec;

int dfs(int x){
    int rslt = 0;  
    for(int i = 0; i < n;i++){
        if(vec[i].first<vec[x].first&&vec[i].second<vec[x].second)
            rslt = max(rslt,dfs(i));
    }
    return rslt+1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0 ; i < n;i++){
        int a,b;
        cin >> a>>  b;
        vec.push_back({a,b});
    }
    int ans = 0;
    for(int i = 0 ; i < n ;i++){
        ans = max(ans,dfs(i));
    }
    cout << ans;
}