#include <iostream>

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int M, m;
    int ll, lm, lr, sl, sm, sr, a, b, c;
    cin >> a >> b >> c;
    ll = a, lm = b, lr = c;
    sl = a, sm = b, sr = c;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        int A = a, B = b, C = c;
        a += max(ll, lm), b += max(max(ll, lm), lr), c += max(lm, lr);
        ll = a, lm = b, lr = c;
        A += min(sl, sm), B += min(min(sl, sm), sr), C += min(sm, sr);
        sl = A, sm = B, sr = C;
    }

    cout << max(max(ll, lm), lr) << ' ' << min(min(sl, sm), sr);
}