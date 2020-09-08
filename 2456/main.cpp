#include <iostream>

int N;
int map[3][4];

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        map[0][a-1]++;
        map[1][b-1]++;
        map[2][c-1]++;
    }

    map[0][3] = map[0][0] + map[0][1] + map[0][2];
    map[1][3] = map[1][0] + map[1][1] + map[1][2];
    map[2][3] = map[2][0] + map[2][1] + map[2][2];

    if (map[0][3] > map[1][3] && map[0][3] > map[2][3]) {
        printf("%d %d", 1, map[0][3]);
        return 0;
    }
    if (map[1][3] > map[0][3] && map[1][3] > map[2][3]) {
        printf("%d %d", 2, map[1][3]);
        return 0;
    }
    if (map[2][3] > map[1][3] && map[0][3] < map[2][3]) {
        printf("%d %d", 3, map[2][3]);
        return 0;
    }

}