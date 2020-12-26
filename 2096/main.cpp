#include <iostream>

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int d1[2][3];
int d2[2][3];
int board[3];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> board[0] >> board[1] >> board[2];
        if (i == 0) {
            d1[0][0] = d2[0][0] = board[0];
            d1[0][1] = d2[0][1] = board[1];
            d1[0][2] = d2[0][2] = board[2];
        }
        else {
            d1[1][0] = max(d1[0][0], d1[0][1]) + board[0];
            d1[1][1] = max(d1[0][2], max(d1[0][0], d1[0][1])) + board[1];
            d1[1][2] = max(d1[0][2], d1[0][1]) + board[2];
            d1[0][0] = d1[1][0];
            d1[0][1] = d1[1][1];
            d1[0][2] = d1[1][2];
            d2[1][0] = min(d2[0][0], d2[0][1]) + board[0];
            d2[1][1] = min(d2[0][2], min(d2[0][0], d2[0][1])) + board[1];
            d2[1][2] = min(d2[0][2], d2[0][1]) + board[2];
            d2[0][0] = d2[1][0];
            d2[0][1] = d2[1][1];
            d2[0][2] = d2[1][2];
        }
    }
    
    cout << max(max(d1[0][0], d1[0][1]), d1[0][2]) <<' '<< min(min(d2[0][0], d2[0][1]), d2[0][2]);
}