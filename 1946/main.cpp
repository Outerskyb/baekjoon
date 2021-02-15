#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            vec.push_back({ a,b });
        }
        sort(vec.begin(), vec.end());
        int ans = 1;
        int M = vec.front().second;
        for (int i = 1; i < n; i++) {
            if (vec[i].second <= M) {
                ++ans;
                M = vec[i].second;
            }
        }
        cout << ans << '\n';
    }
}