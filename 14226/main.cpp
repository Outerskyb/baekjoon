#include <iostream>
#include <queue>

using namespace std;

bool visit[1200][1200];

struct st {
    int y;
    int x;
    int l;
};

int main()
{
    int s;
    cin >> s;

    queue<st> q;
    q.push({ 1,0,0 });
    visit[1][0] = true;
    while (!q.empty()) {
        auto y = q.front().y;
        auto x = q.front().x;
        auto l = q.front().l;
        q.pop();
        if (y == s) {
            cout << l;
            return 0;
        }
        if (!visit[y][y]) q.push({ y,y,l + 1 }), visit[y][y] = true;;
        if (y+x<=1200&&!visit[y + x][x]) q.push({ y + x,x,l + 1 }), visit[y + x][x] = true;;
        if (y>0&&!visit[y - 1][x])q.push({ y - 1,x,l + 1 }), visit[y - 1][x] = true;;
    }


}