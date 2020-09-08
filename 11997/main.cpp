#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define MAX(A,B) (((A)>(B))?(A):(B))

int N;
int map[1001][1001];

unordered_map<int, int> X, Y;
int GetM(int a, int b) {
    return MAX(MAX(map[X.size()][Y.size()] - map[X.size()][b]-map[a][Y.size()]+map[a][b], map[X.size()][b] - map[a][b]), MAX(map[a][b], map[a][Y.size()] - map[a][b]));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    memset(map, 0, sizeof map);
    set<int> sX, sY;
    vector<pair<int, int>> cow;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        cow.push_back(make_pair(x, y));
        sX.insert(x), sY.insert(y);
    }
    
    int cnt = 0;
    for (auto& el : sX) {
        X[el] = cnt++;
    }
    cnt = 0;
    for (auto& el : sY) {
        Y[el] = cnt++;
    }

    for (int i = 0; i < N; i++) {
        map[X[cow[i].first] + 1][Y[cow[i].second] + 1]++;
    }

    for (int i = 1; i <= X.size(); i++) {
        for (int j = 1; j <= Y.size(); j++) {
            map[i][j] += map[i][j - 1] + map[i - 1][j] - map[i - 1][j - 1];
        }
    }

    int min = 987654321;
    for (int i = 1; i <= X.size(); i++) {
        for (int j = 1; j <= Y.size(); j++) {
            if (min > GetM(i, j))  min = GetM(i, j);
        }
    }
    cout << min;



    return 0;
}