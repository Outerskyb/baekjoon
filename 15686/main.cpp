#include <iostream>

using namespace std;

int map[50][50];

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N*N; i++) {
        scanf("%d", &map[i / N][i % N]);
    }
}
