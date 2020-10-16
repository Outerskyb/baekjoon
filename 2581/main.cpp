#include "bits/stdc++.h"

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    bool prim[10001];
    memset(prim,1,sizeof prim);
    set<int> p;
    for (int i = 2; i <= n; i++) {
        if (prim[i]){
            for (int j = i; j <= n; j+=i) prim[j] = 0;
            p.insert(i);
        }
    }
    int sum  = 0;
    for(auto it = p.lower_bound(m);it!=p.upper_bound(n);++it){
        sum += *it;
    }
    if(sum==0){
        cout<<-1;
        return 0;
    }
    cout <<sum<<'\n';
    cout << *(p.lower_bound(m));
}