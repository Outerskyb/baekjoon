#include <iostream>
#include <vector>
#include <algorithm>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

vector<vector<pair<int, int>>> vec;

int ans = 0;

int get(int node) {
    
    vector<int> results;
    for (auto& el : vec[node]) {
        results.push_back(get(el.first) + el.second);
    }
    if (results.size() == 0)
        return 0;
    if (results.size() == 1)
        return results[0];

    sort(results.rbegin(), results.rend());
    ans = max(ans, results[0]+results[1]);
    return results[0];
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N+1; i++) {
        vec.push_back(vector<pair<int, int>>());
    }

    while (--N) 
    {
        int p, c, w;
        cin >> p >> c >> w;
        vec[p].push_back({ c,w });//top down
        //vec[c].push_back({ p,w });
    }
    // we need to select two children of each node 
    // // get in to get out
    // only root node works it
    // the others need just one branch

    ans = max(get(1),ans);

    cout << ans;

}