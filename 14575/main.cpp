#include<iostream>
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;

int main() {
    int N, T;
    int L[1000] = { 0, };
    int R[1000] = { 0, };
    int max = 0, Rmax = 0;
    scanf("%d", &N);
    scanf("%d", &T);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &L[i], &R[i]);
    for (int i = 0; i < N; i++) {
        if (L[i] > max)max = L[i];
        if (R[i] > Rmax)Rmax = R[i];
    }
    for (int s = max; s <= Rmax; s++) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += min(R[i], s);
        }
        if (sum >= T) {
            printf("%d", s);
            return 0;
        }
    }
    printf("%d", -1);

}