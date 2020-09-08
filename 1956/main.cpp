#include <iostream>
#include <climits>
int map[401][401];


int main()
{
    for (int i = 0; i < 401; i++) {
        for (int j = 0; j < 401; j++) map[i][j] = 999999;
    }
    int V, E;
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        map[a][b] = c;
    }

    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                if (map[i][j] > map[i][k] + map[k][j])
                    map[i][j] = map[i][k] + map[k][j];

    int min = INT_MAX;
    for (int i = 1; i <= V; i++) {
        if (map[i][i] < min) min = map[i][i];
    }
    if(min != 999999)
    printf("%d", min);
    else printf("-1");
}