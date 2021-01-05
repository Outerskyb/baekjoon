#include <iostream>

using namespace std;

int lis[1001];
int lds[1001];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int input[1001];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input[i+1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (input[j]<input[i]&&lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    for (int i = n; i > 0; i--) {
        for (int j = n; j > i ; j--) {
            if (input[j] < input[i] && lds[i] < lds[j] + 1) {
                lds[i] = lds[j] + 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (lds[i] + lis[i] > ans)
             ans = lds[i] + lis[i] ;
    }
    cout << ans;
}