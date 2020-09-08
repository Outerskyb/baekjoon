#include <vector>
#include <queue>

using namespace std;

int main()
{
    int v, e;
    scanf("%d %d", &v, &e);

    std::vector<vector<pair<int, int>>> adjList(v+1);

    std::vector<bool> visit(v+1, false);
    std::vector<int> dist(v+1, INT_MAX);
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    int start;
    scanf("%d", &start);

    pq.push(make_pair(0, start));
    dist[start] = 0;

    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adjList[u].push_back(make_pair(v, w));
    }

    int current = start;

    while (!visit[current])
    {
        visit[current] = true;
        for (auto edge : adjList[current]) {
            if (!visit[edge.first] && dist[edge.first] > dist[current] + edge.second) dist[edge.first] = dist[current] + edge.second,
                pq.push(make_pair(dist[edge.first],edge.first));
        }
        while (visit[current] && !pq.empty()) {
            current = pq.top().second;
            pq.pop();
        } 
    }

    for (int i = 1; i < v+1; i++) {
        if(dist[i] != INT_MAX)  printf("%d\n", dist[i]);
        else printf("INF\n");
    }
    return 0;
}