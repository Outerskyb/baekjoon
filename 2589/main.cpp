#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

char**          map;
bool**          visited;
int             N, M;


typedef struct ordered_pair {
    int x;
    int y;
    int distance;
}ordered_pair;

int bfs(int i, int j) {
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < M; b++) {
            visited[a][b] = false;
        }
    }
    queue<ordered_pair> que;
    que.push({ i,j ,0 });
    int current_distance = 0;
    while (!que.empty()) {
        ordered_pair now = que.front();
        if (now.x != N - 1 && map[now.x + 1][now.y + 0] == 'L' && !visited[now.x + 1][now.y + 0]) {
            visited[now.x + 1][now.y + 0] = true;
            que.push({ now.x + 1,now.y + 0,now.distance + 1 });
            current_distance = now.distance+1;
        }
        if (now.y != M - 1 && map[now.x + 0][now.y + 1] == 'L' && !visited[now.x + 0][now.y + 1]) {
            visited[now.x + 0][now.y + 1] = true;
            que.push({ now.x + 0,now.y + 1,now.distance + 1 });
            current_distance = now.distance + 1;
        }
        if (now.x != 0 && map[now.x - 1][now.y + 0] == 'L' && !visited[now.x - 1][now.y + 0]) {
            visited[now.x - 1][now.y + 0] = true;
            que.push({ now.x - 1,now.y + 0 ,now.distance + 1 });
            current_distance = now.distance + 1;
        }
        if (now.y != 0 && map[now.x + 0][now.y - 1] == 'L' && !visited[now.x + 0][now.y - 1]) {
            visited[now.x + 0][now.y - 1] = true;
            que.push({ now.x + 0,now.y - 1 ,now.distance + 1 });
            current_distance = now.distance + 1;
        }

        que.pop();
    }

    return current_distance;
}

void input(void) {
    scanf("%d %d\n", &N, &M);

    //graph = (int**)malloc(sizeof(int*)*N);
    map = (char**)malloc(sizeof(char*)*N);
    visited = (bool**)malloc(sizeof(bool*)*N);
    for (int i = 0; i < N; i++) {
        //graph[i] = (int*)malloc(sizeof(int)*M);
        map[i] = (char*)malloc(sizeof(char)*M);
        visited[i] = (bool*)malloc(sizeof(bool)*M);
        for (int j = 0; j < M; j++) {
            scanf("%c", &map[i][j]);
            visited[i][j] = false;
        }
        getchar();
    }
}

int main() {
    input();
    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'L'&&max < bfs(i, j)) {
                max = bfs(i, j);
            }
        }
    }

    printf("%d", max);
    return 0;
}