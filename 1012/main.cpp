#include <iostream>
#include <cstring>
using namespace std;

bool map[50][50];
bool visit[50][50];

void flood_fill(int y, int x)
{
    visit[y][x] = true;
    if (y != 49 && map[y + 1][x] && !visit[y + 1][x]) {
        flood_fill(y + 1, x);
    }
    if (y != 0 && map[y - 1][x] && !visit[y - 1][x]) {
        flood_fill(y - 1, x);
    }
    if (x != 49 && map[y][x + 1] && !visit[y][x + 1]) {
        flood_fill(y, x + 1);
    }
    if (x != 0 && map[y][x - 1] && !visit[y][x - 1]) {
        flood_fill(y, x - 1);
    }
}

void init()
{
    memset(map, 0, 2500);
    memset(visit, 0, 2500);
}

int main()
{
    int T;
    int M, N, K;
    scanf("%d", &T);
    while (T--)
    {
        int x, y, count = 0;
        init();
        scanf("%d %d %d", &M, &N, &K);
        for (int i = 0; i < K; i++) {
            scanf("%d %d", &x, &y);
            map[y][x] = true;
        }
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                if (map[i][j] && !visit[i][j]) {
                    flood_fill(i, j);
                    count++;
                }
            }
        }
        printf("%d\n", count);
    }
}