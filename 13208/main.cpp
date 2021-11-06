#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cstring>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int N, M;
int cost[500][500];

using pii = pair<int, int>;

struct query {
    int s;
    int e;
    int l;
    int m;
    int h;
};

struct edge {
    pii s;
    pii e;
    int weight;
};

pii parents[500][500];

pii find(pii p) {
    if (parents[p.first][p.second].first < 0) return p;
    return parents[p.first][p.second] = find(parents[p.first][p.second]);
}

void merge(pii p1, pii p2) {
    p1 = find(p1);
    p2 = find(p2);
    if (p1 == p2) return;
    else parents[p2.first][p2.second] = p1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    vector<int> C(N);
    vector<edge> edges;

    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cost[i][j] = C[i] * C[j];
             edges.push_back({ { i,j }, {i,j},cost[i][j] });
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        for (int j = 0; j < N; j++) {
            edges.push_back({ { a,j }, {b,j},max(cost[a][j],cost[b][j]) });
            //edges.push_back({ { j,b }, {j,a},max(cost[j][b],cost[j][a]) });
        }
    }

    sort(edges.begin(), edges.end(), [](edge e1, edge e2) {return e1.weight < e2.weight; });

    int edge_size = edges.size();
    int M = edges[edge_size - 1].weight;

    unordered_set<int> set_weights;
    for (const auto& edge : edges) set_weights.insert(edge.weight);
    vector<int> weights = vector<int>(set_weights.begin(), set_weights.end());
    sort(weights.begin(), weights.end());

    int highst = weights.size();

    int q;
    cin >> q;
    vector<query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].s >> queries[i].e;
        --queries[i].s, --queries[i].e;
        queries[i].l = 0, queries[i].h = highst + 1, queries[i].m = (highst + 1) / 2;
    }

    vector<int> ans(q);
    bool clear = true;
    while (clear) {
        memset(parents, -1, sizeof parents);
        vector<vector<int>> mids(highst + 1);
        clear = false;
        for (int i = 0; i < q; i++) {
            if (queries[i].l + 1 < queries[i].h) {
                mids[queries[i].m].push_back(i);
                clear = true;
            }
        }
        if (!clear) break;
        int current_weight = 0;
        int weight_cnt = -1;
        for (int i = 0; i < edge_size; i++) {
        here:
            if (find(edges[i].s) != find(edges[i].e)) {
                weight_cnt++;
                merge(edges[i].s, edges[i].e);
                current_weight = edges[i].weight;
            }
            while (i < edge_size - 1 && edges[i + 1].weight == current_weight) {
                i++;
                if (find(edges[i].s) != find(edges[i].e)) {
                    merge(edges[i].s, edges[i].e);
                }
            }
            for (auto j : mids[weight_cnt + 1]) {
                //checker 
                bool check = false;
                for (int k = 0; k < N; k++) {
                    if (find({ queries[j].s,queries[j].e }) == find({k,k })) {
                        check = true;
                    }
                }
                if (check) {
                    queries[j].h = weight_cnt + 1;
                    ans[j] = current_weight;
                }
                else {
                    queries[j].l = weight_cnt + 1;
                }
                queries[j].m = (queries[j].l + queries[j].h) / 2;
            }
        }
    }

    for (int j = 0; j < q; j++) {
        cout << max(max(ans[j], cost[queries[j].s][queries[j].e]), cost[queries[j].e][queries[j].s]) << '\n';
    }

}