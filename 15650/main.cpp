#include "bits/stdc++.h"

using namespace std;
vector<vector<int>> vec;

int n,m;

void func(vector<int> stat,int curr, int left){
    if(left == 0) {
        vec.push_back(stat);
        return;
    }
    for(int i = curr; i <= n; i++){
        stat.push_back(i);
        func(stat,i+1,left-1);
        stat.pop_back();
    }
}

int main()
{
    
    cin >> n >> m;
    func(vector<int>(), 1, m);
    for(const auto& v : vec){
        for(const auto& el : v){
            cout << el <<' ';
        }
        cout << '\n';
    }
}