#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        auto it = mp.find(temp);
        if (it != mp.end()) {
            ++(*it).second;
        }
        else {
            mp.insert({ temp,0 });
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        if (mp.find(temp) != mp.end()) {
            cout << "1 ";
        }
        else
            cout << "0 ";
    }
}