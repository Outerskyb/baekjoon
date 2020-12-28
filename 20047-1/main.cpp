#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct s {
    int left;
    int bias;
    bool su;
    bool u1;
    bool u2;
};

int main()
{
    int n;
    cin >> n;

    string str1, str2;
    cin >> str1 >> str2;
    int p1, p2;
    cin >> p1 >> p2;
    queue<s> q;
    q.push({ 0,0,0,0 });
    while (!q.empty()) {
        auto left = q.front().left;
        auto bias = q.front().bias;
        auto su = q.front().su;
        auto u1 = q.front().u1;
        auto u2 = q.front().u2;
        q.pop();

        bool unclear = false;
        for (int i = left; i < n; i++) {
            if (str2[i] == str1[i - bias] && str2[i] == str1[p1]) su = true;
            if (bias && ((u1 && i == p1) || (u2 && i == p2))) bias--;
            if (i - bias >= 0 && str1[i - bias] != str2[i]) {
                if (!u1 && str2[i] == str1[p1]) {
                    q.push({ i,1 + (int)u2,su,true,u2 });
                }
                else if (su && !u2 && str2[i] == str1[p2]) {
                    q.push({ i,1 + (int)u1,su,u1,true });
                }
                else if (!u1&&!u2) {
                    q.push({ i,-1,su,true,u2 });
                }
                else if ( su && !u2) {
                    q.push({ i,bias-1,su,true,u2 });
                }
                else {
                    unclear = true;
                    break;
                }
            }
        }
        if (!unclear) {
            cout << "YES";
            return 0;
        }

    }

    cout << "NO";
}