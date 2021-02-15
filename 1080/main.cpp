#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<string> a, b;


    for (int i = 0; i < N ; i++) {
        string str;
        cin >> str;
        a.push_back(str);
    }
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        b.push_back(str);
    }
    int cnt = 0;
    int sx = N , sy = M ;
    for (int i = 0; i < sx-2; i++) {
        for (int j = 0; j < sy-2; j++) {
            if (a[i][j] != b[i][j]) {
                cnt++;
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        if (a[x][y] == '0') a[x][y] = '1';
                        else if (a[x][y] == '1') a[x][y] = '0';
                    }
                }
            }
        }
    }

    for (int i = 0; i < sx; i++) {
        for (int j = 0; j < sy; j++) {
            if (a[i][j] != b[i][j]) {
                cout << -1; return 0;
            }
        }
    }
    cout << cnt;
}