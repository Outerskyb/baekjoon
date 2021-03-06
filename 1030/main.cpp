#include <iostream>
#include <cmath>
#include <cinttypes>

using namespace std;

int64_t s, N, K, r1, r2, c1, c2;
int color(int64_t r, int64_t y, int64_t x)
{
    if (y > r || x > r) return 0;
    int yb = 0, xb = 0;
    while (r > 1) {
        if (y >= r * (N - K) / 2 / N + yb && y < r * (N + K) / 2 / N + yb
            && x >= r * (N - K) / 2 / N + xb && x < r * (N + K) / 2 / N + xb) {
            return 1;
        }
        yb += r / N * ((y-yb) / (r / N));
        xb += r / N * ((x-xb) / (r / N));
        r /= N;
    }
    return 0;
}

int main()
{
    cin >> s >> N >> K >> r1 >> r2 >> c1 >> c2;

    int r = pow(N, s);
    
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            cout << (color(r, i, j)?"1":"0");
        }
        cout << '\n';
    }
}

/* 
10 3 1 0 2 0 2
10 4 2 0 3 0 3
10 5 1 0 4 0 4
10 5 3 0 4 0 4
10 6 2 0 5 0 5
10 6 4 0 5 0 5
10 7 1 0 6 0 6
10 7 3 0 6 0 6
10 7 5 0 6 0 6
10 8 2 0 7 0 7
10 8 4 0 7 0 7
10 8 6 0 7 0 7
*/