#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    set<pair<int, int>> jems;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        jems.insert({ a,b });
    }
    vector<int> c;
    for (int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        c.push_back(temp);
    }
    sort(c.begin(), c.end());
    
    int sum = 0;
    for (auto it = c.begin(); it != c.end(); ++it) {
        const auto that = --jems.upper_bound({ *it,9876543 });
        if (that == jems.end()) continue;
        sum += (*that).second;
        jems.erase(that);
    }
    cout << sum;
}