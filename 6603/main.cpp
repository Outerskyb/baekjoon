#include <iostream>

using namespace std;

int n;
int nums[13];
int rslt[6];

void dfs(int s, int d) {
    if (d == 6) {
        for (int i = 0; i < 6; i++)
            cout << rslt[i] <<' ';
        cout << '\n';
        return;
    }
    for (int i = s; i < n; i++) {
        rslt[d] = nums[i];
        dfs(i + 1, d + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (1) {
        cin >> n;
        if (!n) return 0;
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        dfs(0, 0);
        cout << '\n';
    }
}