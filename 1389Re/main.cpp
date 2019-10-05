#include <iostream>
#include <queue>
using namespace std;

bool map[200][200];
bool visit[200][200];

void zv() {
    memset(visit, 0, 200);
}

void bfs() {

}

int main() 
{
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a][b] = map[b][a] = true;
    }
    for (int i = 0; i < N; i++) {
        
    }
}