#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[100][100];
int visited[100][100];
int dist[100][100];

struct mypair {
    int x;
    int y;
};

void bfs() {
    queue<mypair> que;
    que.push({ 0,0 });
    dist[0][0] = 0;
    visited[0][0] = 1;
    int current_distance = 0;
    while (!que.empty()) {
        mypair now = que.front();
        if (now.x != M - 1 && map[now.y + 0][now.x + 1] == '1' && !visited[now.y + 0][now.x + 1]) {
            visited[now.y + 0][now.x + 1] = true;
            que.push({ now.x + 1,now.y + 0 });
            dist[now.y + 0][now.x + 1] = dist[now.y][now.x] + 1;
        }
        if (now.y != N - 1 && map[now.y + 1][now.x + 0] == '1' && !visited[now.y + 1][now.x + 0]) {
            visited[now.y + 1][now.x + 0] = true;
            que.push({ now.x + 0,now.y + 1 });
            dist[now.y + 1][now.x + 0] = dist[now.y][now.x] + 1;
        }
        if (now.x != 0 && map[now.y + 0][now.x - 1] == '1' && !visited[now.y + 0][now.x - 1]) {
            visited[now.y + 0][now.x - 1] = true;
            que.push({ now.x - 1,now.y + 0 });
            dist[now.y + 0][now.x - 1] = dist[now.y][now.x] + 1;
        }
        if (now.y != 0 && map[now.y - 1][now.x + 0] == '1' && !visited[now.y - 1][now.x + 0]) {
            visited[now.y + 0][now.x + 1] = true;
            que.push({ now.x + 0,now.y - 1 });
            dist[now.y - 1][now.x + 0] = dist[now.y][now.x] + 1;
        }
        current_distance = dist[now.y][now.x] + 1;
        que.pop();
    }

}

int main() {
    scanf("%d %d", &N, &M);
    getchar();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%c", &map[i][j]);
            visited[i][j] = 0;
            dist[i][j] = 0;
        }
        getchar();
    }
    bfs();
    printf("%d", dist[N-1][M-1]+1);
}