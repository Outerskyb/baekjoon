#include <iostream>
#include <vector>
#include <algorithm>
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> w(10000);
    for (int i = 0; i < n*2; i++) {
        cin >> w[i];
    }
    sort(w.begin(), w.begin()+n*2);
    int m = 987654321;
    for (int i = 0; i < n; i++) {
        m = min(m, w[i]+ w[2 * n - i-1]);
    }
    cout << m;
}