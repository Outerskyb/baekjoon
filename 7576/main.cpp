#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int M, N;
bool visited[1000][1000] = { 0, };
int map[1000][1000];

struct my_tuple {
    int x;
    int y;
    int distance;
};

int bfs() {
    queue<my_tuple> que;
    int minus_count = 0;
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < M; b++) {
            visited[a][b] = false;
            if (map[a][b] == 1) {
                que.push({ a,b,0 });
                visited[a][b] = true;
            }
            if (map[a][b] == -1) minus_count++;
        }
    }

    if (minus_count == N*M) {
        return 0;
    }
    int current_distance = 0;
    while (!que.empty()) {
        my_tuple now = que.front();
        if (now.x != N - 1 && map[now.x + 1][now.y + 0] != -1 && !visited[now.x + 1][now.y + 0]) {
            visited[now.x + 1][now.y + 0] = true;
            que.push({ now.x + 1,now.y + 0,now.distance + 1 });
            current_distance = now.distance + 1;
        }
        if (now.y != M - 1 && map[now.x + 0][now.y + 1] != -1 && !visited[now.x + 0][now.y + 1]) {
            visited[now.x + 0][now.y + 1] = true;
            que.push({ now.x + 0,now.y + 1,now.distance + 1 });
            current_distance = now.distance + 1;
        }
        if (now.x != 0 && map[now.x - 1][now.y + 0] != -1 && !visited[now.x - 1][now.y + 0]) {
            visited[now.x - 1][now.y + 0] = true;
            que.push({ now.x - 1,now.y + 0 ,now.distance + 1 });
            current_distance = now.distance + 1;
        }
        if (now.y != 0 && map[now.x + 0][now.y - 1] != -1 && !visited[now.x + 0][now.y - 1]) {
            visited[now.x + 0][now.y - 1] = true;
            que.push({ now.x + 0,now.y - 1 ,now.distance + 1 });
            current_distance = now.distance + 1;
        }

        que.pop();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == false&&map[i][j] != -1) {
                return -1;
            }
        }
    }

    return current_distance;
}
    
    


int main() 
{   
    scanf("%d %d", &M, &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
   
    printf("%d", bfs());

    return 0;
}