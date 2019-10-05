#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;

std::vector<std::vector<int>> combinations;


bool visit[15][15];
int map[15][15] = { 0 };
int map2[15][15];

int N, M, D;
int sum = 0;

void next_combination(int N)
{
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                std::vector<int> a;
                a.push_back(i);
                a.push_back(j);
                a.push_back(k);
                combinations.push_back(a);
            }
        }
    }
}

std::vector<std::pair<int, int>> killed;

void  slaughter() {
    for (auto coord : killed) {
        if (map[coord.first][coord.second] == 0) sum--;
        map[coord.first][coord.second] = 0;
    }
    killed = std::vector<std::pair<int, int>>();
}


queue<pair<int, int>> q;

void bfs(int x, int y)
{   
    q.push(make_pair(x, y));
    while (!q.empty()) {
        pair<int, int> a = q.front();
        q.pop();
        if (visit[a.second][a.first] || abs(a.first-x)+abs(a.second-y) > D-1 ) continue;
        visit[a.second][a.first] = true;
        if (map[a.second][a.first] == 1) {
            sum++;
            killed.push_back(make_pair(a.second, a.first));
            return;
        }
        
        if (a.first - 1 < M && a.first - 1 >= 0 && a.second >= 0 && a.second < N) {
            q.push(make_pair(a.first - 1, a.second));
        }
        if (a.first < M && a.first >= 0 && a.second - 1 >= 0 && a.second - 1 < N) {
            q.push(make_pair(a.first, a.second - 1));
        }
        if (a.first + 1 < M && a.first + 1 >= 0 && a.second >= 0 && a.second < N) {
            q.push(make_pair(a.first + 1, a.second));
        }
    }    
}

void down() 
{
    for (int i = N-1; i > 0; i--) {
        for (int j = 0; j < M; j++) {
            map[i][j] = map[i - 1][j];
        }
    }
    for (int j = 0; j < M; j++) {
        map[0][j] = 0;
    }
}


int main()
{

    int answer = 0;
    scanf("%d %d %d", &N, &M, &D);

    next_combination(M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    memcpy(map2, map, 15 * 15 * sizeof map[0][0]);

    for (auto set : combinations)
    {
        sum = 0;
        memcpy(map, map2, 15 * 15 * sizeof map[0][0]);
        for (int i = 0; i < N; i++) {
            memset(visit, 0, 15 * 15 * 1);
            bfs(set[0], N - 1);
            memset(visit, 0, 15 * 15 * 1);
            bfs(set[1], N - 1);
            memset(visit, 0, 15 * 15 * 1);
            bfs(set[2], N - 1);
            slaughter();
            down();
        }
        if (sum > answer) 
            answer = sum;

    }

    printf("%d", answer);

}