#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> mp, rmp;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        mp.insert({ temp,i });
        rmp.insert({ i,temp });
    }
    vector<int> vec;
    vec.push_back(-1);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        vec.push_back(mp[temp]);
    }
    int M = -1, Midx;
    vector<int> dp(n + 1, 0);
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (vec[j] < vec[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                if (dp[i] > M) Midx = i, M = dp[i];
                
            }
        }
    }
    ans.push_back(vec[Midx]);
    for (int i = Midx-1; i > 0; i--) {
        if (vec[i] < vec[Midx] && dp[i] == dp[Midx] - 1) {
            ans.push_back(vec[i]);
            Midx = i;
        }
    }

    vector<int> rslt;
    cout << M << '\n';
    for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
        rslt.push_back(rmp[*it]);
    }
    sort(rslt.begin(), rslt.end());
    for (auto el : rslt) {
        cout << el << ' ';
    }
}