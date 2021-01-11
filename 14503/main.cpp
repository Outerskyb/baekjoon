#include <iostream>

using namespace std;

int board[50][50];
bool isclean[50][50];

pair<int, int> l[] = { {0,-1},{-1,0},{0,1},{1,0} };
pair<int, int> b[] = { {2,0},{0,-2},{-2,0},{0,2} };



int main()
{
    int n, m;
    cin >> n >> m;
    int r, c, d;
    cin >> r >> c >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int cnt = 0;
    bool skip = false;
    while (1) {
        if (!skip&&!isclean[r][c]) {
            isclean[r][c] = true;
            cnt++;
            skip = false;
        }
        else if (!board[r + l[d].first][c + l[d].second] && !isclean[r + l[d].first][c + l[d].second]) {
            r += l[d].first, c += l[d].second;
            d += 3, d %= 4;
            skip = false;
        }
        else if ((board[r + l[0].first][c + l[0].second] || isclean[r + l[0].first][c + l[0].second])
            &&   (board[r + l[1].first][c + l[1].second] || isclean[r + l[1].first][c + l[1].second])
            &&   (board[r + l[2].first][c + l[2].second] || isclean[r + l[2].first][c + l[2].second])
            &&   (board[r + l[3].first][c + l[3].second] || isclean[r + l[3].first][c + l[3].second])
            && !board[r+l[(d+3)%4].first][c + l[(d + 3) % 4].second]) {
            skip = true;
            r += b[d].first, c += b[d].second;
        }
        else if ((board[r + l[0].first][c + l[0].second] || isclean[r + l[0].first][c + l[0].second])
            && (board[r + l[1].first][c + l[1].second] || isclean[r + l[1].first][c + l[1].second])
            && (board[r + l[2].first][c + l[2].second] || isclean[r + l[2].first][c + l[2].second])
            && (board[r + l[3].first][c + l[3].second] || isclean[r + l[3].first][c + l[3].second])) {
            break;
        }
        else if (board[r + l[d].first][c + l[d].second] || isclean[r + l[d].first][c + l[d].second]) {
            d += 3, d %= 4;
            skip = false;
        }
    }
    cout << cnt;
}