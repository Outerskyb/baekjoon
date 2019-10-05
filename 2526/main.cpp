#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N, P;
    int count = 0;
    int now = 0;

    queue<int> que;
    scanf("%d %d", &N, &P);
    que.push(N);

    while (count!= que.size()) {
        now = que.back();
        if ((now*N)%P == que.front()) {
            count++;
            que.pop();
        }
        else {
            count = 0;
        }
        que.push((now*N) % P);
    }
    printf("%d", count);
}