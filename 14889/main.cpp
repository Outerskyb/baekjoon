#include <iostream>
#include <cmath>

using namespace std;

int board[20][20];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    int min = 9876546321;
    for (int i = 0; i < pow(2,n); i++) {
        int s = 0, l = 0;
        int j = i;
        int cnt = 0;
    }
}