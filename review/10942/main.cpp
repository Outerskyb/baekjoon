#include <iostream>
#include <cstring>

using namespace std;

int board[2001];
int pal[2001][2001];

int func(int s,int e){
    if (pal[s][e] != -1) return pal[s][e];
    if (board[s] != board[e]) return pal[s][e] = 0;
    else if (s + 1 == e) return pal[s][e] = 1;
    else return pal[s][e] = func(s + 1, e - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n;
    memset(pal, -1, sizeof pal);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        pal[i][i] = 1;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        --s, --e;
        cout << func(s, e)<<'\n';
    }
}