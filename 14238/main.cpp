#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int dp[50][50][50];

void func(string str, int a, int b, int c) {
    if (a == 0 && b == 0 && c == 0) {
        cout << str;
        exit(0);
    }
    string temp = str;
    bool is_ok = false;
    if (a > 0) {
        temp.push_back('A');
        func(temp, a - 1, b, c);
        temp.pop_back();
        is_ok = true;
    }
    if (b > 0 && temp[temp.size() - 1] != 'B') {
        temp.push_back('B');
        func(temp, a, b - 1, c);
        temp.pop_back();
        is_ok = true;
    }
    if (c > 0 && temp[temp.size() - 1] != 'C' && temp[temp.size() - 2] != 'C') {
        temp.push_back('C');
        func(temp, a, b, c - 1);
        is_ok = true;
    }
    dp[a][b][c] = is_ok;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;

    int a = 0, b = 0, c = 0;
    for (auto ch : str) {
        if (ch == 'A')
            a++;
        else if (ch == 'B')
            b++;
        else
            c++;
    }

    func("", a, b, c);
    cout << -1;
    return 0;
}