#include <iostream>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int board[500][500];

int main() 
{
    int n, m, b;
    cin >> n >> m >> b;

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m;j++){
            cin >> board[i][j];
        }
    }

    int M = 130000000,ansI = 0;
    for (int h = 256; h >= 0; --h) {
        int val = 0, nB = b;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] > h) {
                    val += ( board[i][j]-h) * 2;
                    nB+= (board[i][j] - h);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] < h) {
                    val += (h - board[i][j]);
                    nB -= (h - board[i][j]);
                    if (nB < 0) {
                        val += 130000000;
                        goto out;
                    }
                }
            }
        }
    out:
        if (val < M) {
            M = val, ansI = h;
        }
    }
    cout << M<<' '<<ansI;
}