#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int map[2001][2001];
pair<int, int> p[2001][2001];

pair<int, int> find(pair<int, int> n)
{
    int a = n.first, b = n.second;
    if (p[a][b].first < 0) return make_pair(a, b);
    return p[a][b] = find(p[a][b]);
}

void Union(pair<int, int> a, pair<int, int> b)
{
    a = find(a);
    b = find(b);
    if (a == b) return;
    p[b.first][b.second] = a;
}

bool is_it_done(vector<pair<int, int>>& vec) {
    auto r = find(vec[0]);
    for (auto& el : vec)
    {
        if (find(el) != r) return false;
    }
    return true;
}

void check(pair<int, int> pr)
{
    if (pr.first + 1 < N && map[pr.first + 1][pr.second]) {
        Union(pr, { pr.first + 1,pr.second });
    }
    if (pr.first - 1 >= 0 && map[pr.first - 1][pr.second]) {
        Union(pr, { pr.first - 1,pr.second });
    }
    if (pr.second + 1 < N && map[pr.first][pr.second + 1]) {
        Union(pr, { pr.first ,pr.second + 1 });
    }
    if (pr.second - 1 >= 0 && map[pr.first][pr.second - 1]) {
        Union(pr, { pr.first ,pr.second - 1 });
    }
}

int main()
{

    int K;
    cin >> N >> K;
    memset(p, -1, sizeof p);
    vector<pair<int, int>> vec;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        vec.emplace_back(x - 1, y - 1);
    }

    for (auto el : vec) {
        map[el.first][el.second] = 1;
    }
    for (auto el : vec) {
        if (el.first + 1 < N && map[el.first + 1][el.second])
            Union(el, { el.first + 1,el.second });

        if (el.first - 1 >= 0 && map[el.first - 1][el.second])
            Union(el, { el.first - 1,el.second });

        if (el.second + 1 < N && map[el.first][el.second + 1])
            Union(el, { el.first ,el.second + 1 });

        if (el.second - 1 >= 0 && map[el.first][el.second - 1] == 0)
            Union(el, { el.first ,el.second - 1 });

    }

    int cnt = 0;
    vector<pair<int, int>> new_bl = vec;
    while (!is_it_done(vec))
    {
        vector<pair<int, int>> old_bl = new_bl;
        new_bl = vector<pair<int, int>>();
        for (auto& el : old_bl)
        {
            if (el.first + 1 < N)
            {
                if (map[el.first + 1][el.second] == 0) {
                    new_bl.push_back({ el.first + 1, el.second });
                    map[el.first + 1][el.second] = 1;
                    Union(el, { el.first + 1,el.second });
                    check({ el.first + 1,el.second });
                }
                else Union(el, { el.first + 1,el.second });

            }
            if (el.first - 1 >= 0)
            {
                if (map[el.first - 1][el.second] == 0) {
                    new_bl.push_back({ el.first - 1, el.second });
                    map[el.first - 1][el.second] = 1;
                    Union(el, { el.first - 1,el.second });
                    check({ el.first - 1,el.second });
                }
                else Union(el, { el.first - 1,el.second });
            }
            if (el.second + 1 < N)
            {
                if (map[el.first][el.second + 1] == 0) {
                    new_bl.push_back({ el.first , el.second + 1 });
                    map[el.first][el.second + 1] = 1;
                    Union(el, { el.first ,el.second + 1 });
                    check({ el.first ,el.second + 1 });
                }
                else Union(el, { el.first ,el.second + 1 });
            }
            if (el.second - 1 >= 0)
            {
                if (map[el.first][el.second - 1] == 0) {
                    new_bl.push_back({ el.first , el.second - 1 });
                    map[el.first][el.second - 1] = 1;
                    Union(el, { el.first ,el.second - 1 });
                    check({ el.first ,el.second - 1 });
                }
                else Union(el, { el.first ,el.second - 1 });
            }
        }
        ++cnt;
    }
    cout << cnt;
}