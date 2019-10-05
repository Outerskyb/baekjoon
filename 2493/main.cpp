#include<iostream>

using namespace std;

int N;
int ary[500000];
int main() {
    int now, now_i;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &ary[i]);
    }
    now = ary[N - 1];
    now_i = N - 1;
    for (int i = N - 2; i >= 0; i--) {
        if (ary[i] >= now) {
            for (int j = i+1; j <= now_i; j++) ary[j] = i+1;
            now = ary[i];
            now_i = i;
        }
    }
    for (int i = 0; i <= now_i; i++) ary[i] = 0;
    for (int i = 0; i < N; i++) {
        printf("%d", ary[i]);
    }
}