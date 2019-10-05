#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;

int main() {
    int N, M;
    int train[100001] = { 0, };//1번기차 부터 있어요
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d", &a, &b);
        switch (a) {
        case 1:
            scanf("%d", &c);
            if((train[b]>>c)%2!=1) train[b] += 1 << c;
            break;
        case 2:
            scanf("%d", &c);
            if((train[b]>>c)%2!=0)train[b] -= pow(2, c);
            break;
        case 3:
            train[b] <<= 1;
            if (train[b] >= (1 << 21)) train[b] -= (1 << 21);
            break;
        case 4:
            train[b] >>= 1;
            if (train[b] % 2 == 1) train[b] -= 1;
            break;
        }
    }
    std::unordered_set<int> set;
    for (int i = 1; i <= N; i++) {
        set.insert(train[i]);
        //printf("%d\n", train[i]);
    }
    printf("%u\n", set.size());
}
