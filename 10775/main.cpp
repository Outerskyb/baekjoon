#include "bits/stdc++.h"

using namespace std;

int p[10001];

int find(int a) {
    if (p[a] == -1) return a;
    return p[a] = find(p[a]);
}

void merge(int small, int large) {
    small = find(small);
    large = find(large);
    if (small == large) return;
    p[large] = small;
}

int main() {
    ios::sync_with_stdio(false);
    int G, P;
    cin >> G >> P;
    memset(p, -1, sizeof p);
    vector<int> g(P);
    int gates[10000] = {0};

    for (int i = 0; i < P; i++) {
        cin >> g[i];
        int a = find(g[i]);
        if (a == 0) {
            cout << i;
            return 0;
        } else {
            merge(a - 1, a);
        }
    }

    cout << P;
}
