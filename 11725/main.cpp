#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pr[100001];
vector<vector<int>> vec;

void bfs(int curr) 
{
    
    for (auto& el : vec[curr]) 
    {
        if (pr[el] != 0) continue;
        pr[el] = curr;
        bfs(el);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vec = vector<vector<int>>(n+1);

    for (int i = 0; i < n-1; i++) 
    {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for (auto& v : vec) {
        sort(v.begin(), v.end());
    }
    bfs(1);
    for (int i = 2; i <= n; i++) cout << pr[i] << '\n';
}