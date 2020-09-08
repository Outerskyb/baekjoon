#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int width, height;
    int N;
    int answer = 0;
    int ary[100][2];
    int man_x,man_y;

    scanf("%d %d", &width, &height);
    scanf("%d %d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &ary[i][0], &ary[i][1]);
    }

    scanf("%d %d", &man_x, &man_y);

    for (int i = 0; i < N; i++) {
        if (ary[i][0] == man_x) {
            answer += abs(man_y - ary[i][1]);
        }
        if (man_x == 0 && ary[i][0] == 2) {
            
        }
    }
}