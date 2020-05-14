#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> vec;
    for(int i = 0 ; i < n ; i++){
        int s, e;
        cin >> s >> e;
        vec.push_back({ e, s });
    }
    sort(vec.begin(), vec.end());
    
    int ans = 1;
    auto now = vec[0].first;

    for (int i = 1; i < vec.size(); i++) {
        if (vec[i].second < now) continue;
        else  now = vec[i].first, ans++;
    }

    cout << ans;
}