#include <iostream>
#include <map>
#include <cstring>
#include <string>

using namespace std;

int p[100001];

int find(int n)
{
    if (p[n] < 0) return n;
    return p[n] = find(p[n]);
}

int size(int n) {
    if (p[n] < 0) return -1 * p[n];
    return size(p[n]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b) return;
    p[a] += p[b];
    p[b] = a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        memset(p, -1, sizeof p);
        int F;
        cin >> F;
        map<string, int> mp;
        int cnt = 0;
        for (int i = 0; i < F; i++) {
            string str1, str2;
            cin >> str1 >> str2;
            if (mp.find(str1) == mp.end()) mp.insert({ str1,cnt++ });
            if (mp.find(str2) == mp.end()) mp.insert({ str2,cnt++ });
            Union(mp[str1], mp[str2]);
            cout << size(mp[str1]) << '\n';
        }
    }
}