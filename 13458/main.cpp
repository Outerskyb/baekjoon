#include "bits/stdc++.h"

using namespace std;

int main() {
    long long N;
    long long B, C;

    cin >> N;
    vector<long long> h(N);
    for (int i = 0; i < N; i++)
        cin >> h[i];
    cin >> B >> C;

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        if (h[i] - B < 0) continue;
        ans += ceil(double(h[i] - B) / C);
    }
    cout << ans + N;
}