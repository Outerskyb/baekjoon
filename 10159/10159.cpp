#include<iostream>

using namespace std;

int N, M;
int mat[102][102];
int inverted_mat[102][102];
int visit[102];
int visit2[102];
int dp[102] = { 0, };
int dp2[102] = { 0, };

int search(int num) {
    int sum = 1;
    visit[num] = 1;
    for (int i = 1; i <= N; i++) {
        if (mat[num][i] == 1) {
            if (dp[i] == 0) {
                sum += search(i);
            }
            else {
                sum += dp[i];
            }
        }
    }
    dp[num] = sum;
    return sum;
}
int search2(int num) {
    int sum = 1;
    visit2[num] = 1;
    for (int i = 1; i <= N; i++) {
        if (inverted_mat[num][i] == 1 ) {
            if (dp2[i] == 0) {
                sum += search2(i);
            }
            else {
                sum += dp2[i];
            } 
        }
    }
    dp2[num] = sum;
    return sum;
}
int main() {
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        mat[a][b] = 1;
        inverted_mat[b][a] = 1;
    }
    for (int i = 1; i < N+1; i++) {
        for (int j = 0; j < N + 1; j++) {
            visit[j] = visit2[j] = 0;
        }
        printf("%d\n", N - search(i)-search2(i)+1);
    }
}
//////
/*
8 8
1 3
2 3
3 4
3 5
5 6
6 7
7 8
4 8

*/