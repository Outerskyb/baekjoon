#include <iostream>

using namespace std;

int main() {
    int X[101], S[101];
    int N, M, g, a, f, Sy, Sx,E;
    scanf("%d %d %d %d %d %d %d %d", &N, &M, &g, &a, &f, &Sy, &Sx, &E);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &X[i], &S[i]);
    }
    if (Sx == E) {
        printf("%f", Sy / float(g));
        return 0;
    }
    else {
        float ans = 999999999;
        for (int i = 0; i < M; i++) {
            float ver = ((Sy - (g / 2.)*(abs(X[i] - Sx) / float(a))) / float(g));
            float ho = (abs(X[i] - Sx) / float(a));
            float left = abs(X[i] - E) / float(S[i]);
            if (ver + ho + left < ans) ans = ver + ho + left;
        }
        printf("%f", ans);
    }
}