#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main()
{
    int N, E;
    scanf("%d %d", &N, &E);
    vector<vector<pair<int, int>>> adjList(N + 1);
    vector<long long int> dist1(N+1, 536870912);
    vector<int> dista(N+1, 536870912);
    vector<int> distb(N+1, 536870912);
    vector<bool> visit(N+1,false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adjList[a].push_back(make_pair(b, c));
        adjList[b].push_back(make_pair(a, c));
    }
    int a, b;
    scanf("%d %d", &a, &b);

    int current = 1;
    dist1[1] = 0;

    while (!visit[current]) {
        visit[current] = true;
        for (auto edge : adjList[current]) {
            if (!visit[edge.first]&& dist1[edge.first] > dist1[current] + edge.second) {
                dist1[edge.first] = dist1[current] + edge.second;
                pq.push(make_pair(dist1[edge.first], edge.first));
            }
        }
        while (visit[current] && !pq.empty()) {
            current = pq.top().second;
            pq.pop();
        }
    }

    current = a;
    visit = vector<bool>(N + 1);
    dista[current] = 0;
    pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();
    while (!visit[current]) {
        visit[current] = true;
        for (auto edge : adjList[current]) {
            if (!visit[edge.first] && dista[edge.first] > dista[current] + edge.second) {
                dista[edge.first] = dista[current] + edge.second;
                pq.push(make_pair(dista[edge.first], edge.first));
            }
        }
        while (visit[current] && !pq.empty()) {
            current = pq.top().second;
            pq.pop();
        }
    }
    current = b;
    visit = vector<bool>(N + 1);
    distb[b] = 0;
    pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();
    while (!visit[current]) {
        visit[current] = true;
        for (auto edge : adjList[current]) {
            if (!visit[edge.first] && distb[edge.first] > distb[current] + edge.second) {
                distb[edge.first] = distb[current] + edge.second;
                pq.push(make_pair(dist1[edge.first], edge.first));
            }        
        }
        while (visit[current] && !pq.empty()) {
            current = pq.top().second;
            pq.pop();
        }
    }
    long long a1 = dist1[a] + dista[b] + distb[N];
    long long a2 = dist1[b] + distb[a] + dista[N];
    
    long long answer = (a1 > 536870912) ? ((a2 > 536870912) ? -1 : a2) : (a2 > 536870912) ? a1 : min(a1, a2);
    printf("%lld", answer);
}