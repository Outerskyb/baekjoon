#include<iostream>

using u64 = unsigned long long int;
using namespace std;

int main() {
    int N, M,T;
    scanf("%d", &T);
    while (T--) {
        u64 result = 1;

        scanf("%d %d", &N, &M);

        if (N == 0) {
            printf("%d", 0);
            return 0;
        }

        for (int i = 0; i < N; i++) {
            result *= (M - i);
        }
        for (int i = N; i > 0; i--) {
            result /= i;
        }
        printf("%d\n", result);
    }
}