#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

pair<int,int> af[27];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> vec;

    int M = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        vec.push_back(s);
        if (s.size() > M) M = s.size();
    }

    int num = 9;
    int ans = 0;
    for (int i = M - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (vec[j].size() <= i) continue;
            af[vec[j][i] - 'A'].second = vec[j][i];
            af[vec[j][i] - 'A'].first += pow(10, i);
        }
    }
    sort(af, af + 27);
    for (int i = 9; i >= 0; i--) {
        if(af[26-9+i].second!=0)
            ans += af[26 - 9 + i].first*i;
    }
    cout << ans;
}