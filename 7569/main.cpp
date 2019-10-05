#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int M, N, H;
bool visited[100][100][100] = { 0, };
int map[100][100][100];

struct my_tuple {
    int x;
    int y;
    int z;
    int distance;
};

int bfs() {
    queue<my_tuple> que;
    int minus_count = 0;
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < M; b++) {
            for (int c = 0; c < H; c++) {
                visited[a][b][c] = false;
                if (map[a][b][c] == 1) {
                    que.push({ a,b,c,0 });
                    visited[a][b][c] = true;
                }
                if (map[a][b][c] == -1) minus_count++;
            }
        }
    }

    if (minus_count == N*M*H) {
        return 0;
    }

    int current_distance = 0;

    while (!que.empty()) {
        my_tuple now = que.front();
        if (now.x != N - 1 && map[now.x + 1][now.y + 0][now.z + 0] != -1 && !visited[now.x + 1][now.y + 0][now.z + 0]) {
            visited[now.x + 1][now.y + 0][now.z + 0] = true;
            que.push({ now.x + 1,now.y + 0,now.z + 0,now.distance + 1 });
            current_distance = now.distance + 1;
        }
        if (now.y != M - 1 && map[now.x + 0][now.y + 1][now.z + 0] != -1 && !visited[now.x + 0][now.y + 1][now.z + 0]) {
            visited[now.x + 0][now.y + 1][now.z + 0] = true;
            que.push({ now.x + 0,now.y + 1,now.z + 0,now.distance + 1 });
            current_distance = now.distance + 1;
        }
        if (now.x != 0 && map[now.x - 1][now.y + 0][now.z + 0] != -1 && !visited[now.x - 1][now.y + 0][now.z + 0]) {
            visited[now.x - 1][now.y + 0][now.z + 0] = true;
            que.push({ now.x - 1,now.y + 0 ,now.z + 0,now.distance + 1 });
            current_distance = now.distance + 1;
        }
        if (now.y != 0 && map[now.x + 0][now.y - 1][now.z + 0] != -1 && !visited[now.x + 0][now.y - 1][now.z + 0]) {
            visited[now.x + 0][now.y - 1][now.z + 0] = true;
            que.push({ now.x + 0,now.y - 1 ,now.z + 0,now.distance + 1 });
            current_distance = now.distance + 1;
        }
        if (now.z != H - 1 && map[now.x + 0][now.y + 0][now.z + 1] != -1 && !visited[now.x + 0][now.y + 0][now.z + 1]) {
            visited[now.x + 0][now.y + 0][now.z + 1] = true;
            que.push({ now.x + 0,now.y + 0 ,now.z + 1,now.distance + 1 });
            current_distance = now.distance + 1;
        }
        if (now.z != 0 && map[now.x + 0][now.y + 0][now.z - 1] != -1 && !visited[now.x + 0][now.y + 0][now.z - 1]) {
            visited[now.x + 0][now.y + 0][now.z - 1] = true;
            que.push({ now.x + 0,now.y + 0 ,now.z - 1,now.distance + 1 });
            current_distance = now.distance + 1;
        }
        que.pop();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < H; k++) {
                if (visited[i][j][k] == false && map[i][j][k] != -1) {
                    return -1;
                }
            }
        }
    }

    return current_distance;
}




int main()
{
    scanf("%d %d %d", &M, &N, &H);
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &map[i][j][k]);
            }
        }
    }

    printf("%d", bfs());

    return 0;
}