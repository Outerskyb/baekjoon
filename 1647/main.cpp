#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int p[100001];

int find(int n)
{
    return (p[n] < 0) ? n : p[n] = find(p[n]);
}

void merge(int a, int b)
{
    a = find(a), b = find(b);
    if (a == b) return;
    p[b] = a;
}

int main()
{
    memset(p, -1, sizeof p);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    
    vector<pair<int, pair<int, int>>> vec;
    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        vec.push_back(make_pair(C, make_pair(A, B)));
    }

    sort(vec.begin(), vec.end());

    int cnt = 0, sum = 0;
    for (auto& el : vec) {
        if (find(el.second.first) != find(el.second.second)){
            merge(el.second.first, el.second.second);
            sum += el.first;
            cnt++;
        }
        if (cnt == N - 2)
        {
            cout << sum;
            return 0;
        }
    }

}