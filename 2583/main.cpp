#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int M, N;
int** map;

void s(int y, int x, int& count) {
    map[y][x] = 1;
    count++;
    if (y + 1 < M && map[y + 1][x] == 0) {
        s(y + 1, x, count);
    }
    if (x + 1 < N && map[y][x + 1] == 0) {
        s(y, x + 1, count);
    }
    if (y - 1 >= 0 && map[y - 1][x] == 0) {
        s(y - 1, x, count);
    }
    if (x - 1 >= 0 && map[y][x - 1] == 0) {
        s(y, x - 1, count);
    }
}

int main() {
    int K;
    scanf("%d %d %d", &M, &N, &K);

    map = (int**)malloc(sizeof(int)*M);
    for (int i = 0; i < M; i++) {
        map[i] = (int*)calloc(N, sizeof(int));
    }

    for (int i = 0; i < K; i++) {
        int x, y, x2, y2;
        scanf("%d %d %d %d", &x, &y, &x2, &y2);
        for (int X = x; X < x2; X++) {
            for (int Y = y; Y < y2; Y++) {
                map[Y][X] = 1;
            }
        }
    }
    vector<int> ans;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 0) {
                int count = 0;
                s(i, j, count);
                ans.push_back(count);
            }
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }

}