#include <iostream>

using namespace std;

int map[21][21];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, y, x, sz = 2, num_eaten = 0;
    cin >> N;
    int cnt[7];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) y = i, x = j;
        }
    }

    

}