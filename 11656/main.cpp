#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    vector<string> vs;
    for (int i = 0; i < str.size(); i++) {
        vs.push_back(str.substr(i, str.size() - i));
    }

    sort(vs.begin(), vs.end());
    for (auto s : vs) {
        cout << s << '\n';
    }
}