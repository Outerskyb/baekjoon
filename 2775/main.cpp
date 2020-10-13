#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int map[15][14] = { {1,2,3,4,5,6,7,8,9,10,11,12,13,14}, };
    
    for (int i = 1; i < 15; i++) {
        for (int j = 0; j < 14; j++) {
            for (int k = 0; k <= j; k++) {
                map[i][j] += map[i - 1][k];
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int k, n;
        cin >> k >> n;
        cout << map[k][n - 1] << '\n';
    }
}