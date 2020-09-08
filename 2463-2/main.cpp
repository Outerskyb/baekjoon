#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int p[100001];

bool is_island[100001];
int is_num;


int find(int n)
{
    return (p[n] < 0) ? n : p[n] = find(p[n]);
}

void merge(int a, int b)
{
    if (is_island[a]) is_island[a] = false,is_num++;
    if(is_island[b]) is_island[b] = false, is_num++;
    a = find(a), b = find(b);
    if (a == b) return;
    p[a] += p[b];
    p[b] = a;
}

int size(int n) {
    return -p[find(n)];
}

//weight 큰순으로 연결하면서 새로연결하는 각 집합 개수 체크 마지막에 나누기
int main()
{
    memset(is_island, 1, sizeof is_island);
    memset(p, -1, sizeof p);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<pair<int, pair<int, int>>> vec;
    for (int i = 0; i < M; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        vec.push_back(make_pair(w, make_pair(x, y)));
    }

    sort(vec.begin(), vec.end());

    long long sum = 0;

    int vers = 0;

    for (int i = 0; i < M; i++) 
    {
        sum += vec[i].first * (N * (N - 1) / 2 - vers);
        if (find(vec[i].second.first) != find(vec[i].second.second))
            vers += size(vec[i].second.first) * size(vec[i].second.second);
        merge(vec[i].second.first,vec[i].second.second);
    }
    /*for (int i = 0; i < M; i++)
    {
        cout << vec[i].first << ' ' << (N - is_num) << ' ' << (N - is_num + 1);
        sum += vec[i].first * (N - is_num) * (N - is_num + 1) ;
        cout << ' ' << sum << '\n';
        merge(vec[i].second.first, vec[i].second.second);
    }*/

    cout << sum;


}