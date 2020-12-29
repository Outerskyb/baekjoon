#include <iostream>
#include <queue>

using namespace std;

bool visit[1001][1001];

struct st {
    int d;
    int c;
    int l;
};

int main() {
    int s;
    cin >> s;

    queue<st> q;
    q.push({1,0,0 });
    while(!q.empty()){
        auto d = q.front().d;
        auto c = q.front().c;
        auto l = q.front().l;
        q.pop();
        if (d == s) {
            cout << l; return 0;
        }
        if (!visit[d][d]) q.push({ d,d,l + 1 }), visit[d][d] = true;
        if (!visit[d+c][c]) q.push({ d+c,c,l + 1 }), visit[d+c][c] = true;
        if (d>0&&!visit[d-1][c]) q.push({ d-1,c,l + 1 }), visit[d-1][c] = true;
    }
}