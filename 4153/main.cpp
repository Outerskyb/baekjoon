#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (1) {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        if (a[0] == 0 && a[1] == 0 && a[2] == 0)
            return 0;
        sort(a, a + 3);
        cout << ((a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) ? "right" : "wrong") << '\n';
    }
}