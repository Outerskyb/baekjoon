#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    map<string, string> mp;
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        mp.insert({ s1,s2 });
    }

    for (int j = 0; j < m; j++) {
        string s;
        cin >> s;
        cout << mp[s]<<'\n';
    }
}