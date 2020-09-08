#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    list<char> l(str.begin(), str.end());

    auto it = l.end();
    int n;
    cin >> n;

    while (n--) {
        char temp;
        cin >> temp;
        if (temp == 'P') {
            char val; cin >> val;
            l.insert(it, val);
        }
        if (temp == 'L' && it != l.begin()) {
            it--;
        }
        if (temp == 'D' && it != l.end()) {
            it++;
        }
        if (temp == 'B' && it != l.begin()) {
            auto temp = --it;
            if (it == l.begin()) { l.erase(it); it = l.begin(); }
            else {
                --temp;
                l.erase(it);
                it = ++temp;
            }
        }
    }
    for (auto& c : l) cout << c;
}