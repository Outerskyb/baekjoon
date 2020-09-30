#include "bits/stdc++.h"

using namespace std;

int main() {
    uint64_t fib[68] = {1,1, 2, 4};
    for (int i = 4; i < 68; i++) {
        fib[i] = fib[i - 1] + fib[i - 2] + fib[i - 3]+fib[i-4];
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << fib[n]<<'\n';
    }
}