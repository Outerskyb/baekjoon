#include <iostream>
#include <map>

using namespace std;

int s = 1;
int t[1048577];

void update(int pos) {
    pos += s;
    t[pos] = 1;
    while (pos > 1) {
        pos /= 2;
        t[pos] = t[pos * 2] + t[pos * 2 + 1];
    }
}

long long sum(int L, int R, int nN, int nL, int nR)
{
    if (nR<L || nL>R) return 0;
    if (L <= nL && nR <= R) return t[nN];
    int mid = (nL + nR) / 2;
    return sum(L, R, nN * 2, nL, mid) + sum(L, R, nN * 2 + 1, mid + 1, nR);
}

int a[500001];
int b[500001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while (s < n) s *= 2;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        mp.insert({ temp,i });
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        update(mp[a[i]]);
        ans += sum(mp[a[i]]+1, n - 1, 1, 0, s - 1);
    }
    cout << ans;
}