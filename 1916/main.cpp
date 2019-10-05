#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;



int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    vector<bool> visit(N+1, false);
    vector<int> dist(N+1, INT_MAX);
    vector<vector<pair<int, int>>> adjList(N+1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adjList[a].push_back(make_pair(b, c));
    }
    int S, E;
    scanf("%d %d", &S, &E);
    pq.push(make_pair(0, S));
    dist[S] = 0;

    int current = S;
    while (!visit[current]) {
        visit[current] = true;
        for (auto edge : adjList[current]) {
            if (!visit[edge.first] && dist[edge.first] > dist[current] + edge.second) {
                dist[edge.first] = dist[current] + edge.second;
                pq.push(make_pair(dist[edge.first], edge.first));
            }
        }
        while (!pq.empty() && visit[current]) {
            current = pq.top().second;
            pq.pop();
        }
    }
    printf("%d", dist[E]);
}