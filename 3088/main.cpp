#include <iostream>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a1, a2, a3;
    int b1, b2, b3;
    cin >> a1 >> a2 >> a3;

    int cnt = 0;
    for (int i = 0; i < n-1; i++) {
        cin >> b1 >> b2 >> b3;
        if ((a1 == b1 || a2 == b1 || a3 == b1
            || a1 == b2 || a2 == b2 || a3 == b2
            || a1 == b3 || a2 == b3 || a3 == b3) && i == n - 2) {
            cnt++;
        }
        else if (a1 == b1 || a2 == b1 || a3 == b1
            || a1 == b2 || a2 == b2 || a3 == b2
            || a1 == b3 || a2 == b3 || a3 == b3) {
            
        }
        else {
            cnt++;
        }
        a1 = b1, a2 = b2, a3 = b3;
    }
    cout << cnt;
}