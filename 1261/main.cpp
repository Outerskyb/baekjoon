#include <cstring>
#include <iostream>
#include <queue>
#include <string>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int map[101][101];
int dist[101][101];

struct pos {
    int y;
    int x;
    int dst;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> M >> N;

    memset(dist, 127, sizeof dist);
    dist[0][0] = 0;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            map[i][j] = str[j] - '0';
        }
    }

    queue<pos> que;
    que.push({ 0,0,0 });

    while (!que.empty()) {
        int x = que.front().x;
        int y = que.front().y;
        int dst = que.front().dst;
        que.pop();

        if (y - 1 >= 0 && dist[y - 1][x] > dst + map[y - 1][x]) {
            dist[y - 1][x] = dst + map[y - 1][x];
            que.push({ y - 1, x, dst + map[y - 1][x] });
        }
        if (y + 1 < N && dist[y + 1][x] > dst + map[y + 1][x]) {
            dist[y + 1][x] = dst + map[y + 1][x];
            que.push({ y + 1, x, dst + map[y + 1][x] });
        }
        if (x - 1 >= 0 && dist[y][x - 1] > dst + map[y][x - 1]) {
            dist[y][x - 1] = dst + map[y][x - 1];
            que.push({ y, x - 1, dst + map[y][x - 1] });
        }
        if (x + 1 < M && dist[y][x + 1] > dst + map[y][x + 1]) {
            dist[y][x + 1] = dst + map[y][x + 1];
            que.push({ y, x + 1, dst + map[y][x + 1] });
        }
    }

    cout << dist[N - 1][M - 1];
}