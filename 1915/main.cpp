#include<iostream>
#include <cmath>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;
int map[1001][1001];
int sum[1000][1000];
int N, M;

bool is_sq(int N) {
    return (sqrt(N) - int(sqrt(N)) == 0);
}

int main()
{
    char a;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N*M; i++) {
        scanf("%c", &a);
        if (a == '0' || a == '1')
            map[i / N+1][i % N+1] = a - '0';
        else i--;

    }

    //적분영상
    for (int i = 0; i < N+1; i++) sum[i][0] = map[i][0];
    for (int i = 0; i < N+1; i++) {
        for (int j = 1; j < M+1; j++) {
            sum[i][j] = sum[i][j - 1] + map[i][j];
        }
    }
    for (int j = 0; j < M+1; j++) {
        for (int i = 1; i < N+1; i++) {
            sum[i][j] = sum[i][j] + sum[i - 1][j];
        }
    }

    int max = 0;

    for (int i = 0; i < N+1; i++) {
        for (int j = 0; j < M+1; j++) {
            if (map[i + 1][j + 1] == 1) {
                if (max == 0)max = 1;
            }
            else continue;
            for (int k = 1; k < min(N,M)+1 - max(i, j); k++) {
                int area = sum[i][j] + sum[i + k][j + k] - sum[i][j + k] - sum[i + k][j];
                if (area > max && is_sq(area)) {
                    max = area;
                }
            }
        }
    }
    printf("%d", max);
}
