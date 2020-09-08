#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <cstring>

//boj.kr/1799

using namespace std;

bool prhbt[10][10];
int map[10][10];
int n, cnt;

bool is_ok(int nums)
{
    set<int> u, d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1) {
                u.insert(i + j), d.insert(i - j);
            }
        }
    }
    if (u.size() != nums || d.size() != nums) return false;
    return true;
}

vector<vector<int>> combination(int n, int r) 
{
    vector<vector<int>> vec;
    vector<int> ar;
    for (int i = 0; i < r; i++) ar.push_back(0);
    for (int i = 0; i < n-r; i++) ar.push_back(1);
    vec.push_back(ar);
    while (next_permutation(ar.begin(), ar.end())) {
        vec.push_back(ar);
    }
    return vec;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<pair<int, int>> pos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            prhbt[i][j] = temp;
            if (temp) pos.push_back({ i,j });
        }
    }

    cnt = pos.size();
    cnt = (cnt > 2 * n - 1) ? 2 * n - 1:cnt ;
    for (int i = cnt; i >= 0; i--) {
        vector<int> ar;
        for (int j = 0; j < i; j++) ar.push_back(0);
        for (int j = 0; j < pos.size() - i; j++) ar.push_back(1);
        while (next_permutation(ar.begin(), ar.end())) {
            memset(map, 0, 10 * 10 * 4);
            for (int j = 0; j < ar.size(); j++) {
                if (ar[j]) {
                    map[pos[j].first][pos[j].second] = 1;
                }
            }
            if (is_ok(i)) {
                cout << i + 1;
                return 0;
            }
        }
    }
}