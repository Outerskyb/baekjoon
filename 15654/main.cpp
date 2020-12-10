#include "bits/stdc++.h"

using namespace std;
vector<vector<int>> vec;

int n,m;
vector<int> input;

bool is_in(vector<int>& stat,int check){
    for(const auto& el : stat){
        if(el == check) return true;
    }
    return false;
}

void func(vector<int> stat, int left){
    if(left == 0) {
        vec.push_back(stat);
        return;
    }
    for(int i = 0; i < n; i++){
        if(is_in(stat,input[i])) continue;
        stat.push_back(input[i]);
        func(stat,left-1);
        stat.pop_back();
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0 ; i<n;i++){
        int temp;
        cin >> temp;
        input.push_back(temp);
    }
    sort(input.begin(),input.end());
    func(vector<int>(),  m);
    for(const auto& v : vec){
        for(const auto& el : v){
            cout << el <<' ';
        }
        cout << '\n';
    }
}