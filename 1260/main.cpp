#include <iostream>

using namespace std;

bool matrix[1001][1001];
bool visit[1001][1001];

int main()
{
    int N, M, V;
    scanf("%d %d %d", &N);

    for (int i = 0; i < M; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        matrix[start][end] = matrix[end][start] = true;
    }

}