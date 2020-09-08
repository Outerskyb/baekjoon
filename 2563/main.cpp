#include<iostream>

using namespace std;

int main() {
    int map[100][100] = { 0, };
    int N;
    scanf("%d", &N);
    int left, bottom;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &left, &bottom);
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++)
                map[left+j][bottom+k]=1;
        }
    }
    int count = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (map[i][j] == 1) count++;
        }
    }
    cout << count;
}