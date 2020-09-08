#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<pair<int, int>> vec;

int dist(pair<int, int> p1,int x,int y) {
    return abs(x - p1.first) + abs(y - p1.second);
}

long long dst(pair<int, int> p) {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += abs(p.first - vec[i].first) + abs(p.second - vec[i].second);
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    
    long long X = 0, Y = 0;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        vec.push_back(make_pair(x, y));
        X += x, Y += y;
    }
    X /= N, Y /= N;

    long long min = 9876543216543;
    int minidx = 0;
    vector<pair<int, pair<int, int>>> cand;
    for (int i = 0; i < N;i++) {
        cand.push_back(make_pair(dist(vec[i],X,Y), vec[i]));
       // if (dist(vec[i], X, Y) < min) min = dist(vec[i], X, Y), minidx = i;
    }
    sort(cand.begin(), cand.end());
    pair<int, int> p;
    for (int i = 0; i < ((150>N)?N:150); i++) {
        if (min > dst(cand[i].second)) {
            min = dst(cand[i].second);
            p = cand[i].second;
        }
    }
    for (int i = 0; i < N; i++) {
        if (vec[i] == p) cout << i + 1;
    }
    //cout << minidx + 1;

}