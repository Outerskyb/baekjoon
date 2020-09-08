#include <iostream>

using namespace std;

int main() {
    int N;
    int input[50][3];
    scanf("%d" ,&N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &input[i][0], &input[i][1]);
    }
    for (int i = 0; i < N; i++) {
        int num = 0;
        for (int j = 0; j < N; j++) {
            if (j == i) {
                continue;
            }
            if (input[j][0] > input[i][0] && input[j][1] > input[i][1]) {
                num++;
            }
        }
        printf("%d ", num+1);
    }
}