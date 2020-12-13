#include "bits/stdc++.h"

using namespace std;

int main() {
    int e = 1, s = 1, m = 1;
    int board[16][29][20];
    int E, S, M;
    cin >> E >> S >> M;
    for (int i = 1; i < 7981; i++, e++, s++, m++) {
        if (e > 15) e = 1;
        if (s > 28) s = 1;
        if (m > 19) m = 1;
        board[e][s][m] = i;
    }
    cout << board[E][S][M];
}