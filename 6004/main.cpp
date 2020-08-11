#include <iostream>
#include <queue>

using namespace std;

struct s {
    int y;
    int x;
    int depth;
};

int map[151][151];
bool visit[151][151];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y;
    cin >> x >> y;

    queue<s> q;
    int dx, dy;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            char temp;
            cin >> temp;
            map[i][j] = temp != '*';
            if (temp == 'K') {
                q.push({i, j, 0});
                visit[i][j] = true;
            } else if (temp == 'H') {
                dx = j;
                dy = i;
            }
        }
    }

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        visit[curr.y][curr.x] = true;
        if (curr.x == dx && curr.y == dy) {
            cout << curr.depth;
            return 0;
        }

        if (curr.y - 2 >= 0) {
            if (curr.x - 1 >= 0) {
                if (/*map[curr.y - 1][curr.x] && map[curr.y - 2][curr.x] &&*/ map[curr.y - 2][curr.x - 1] && !visit[curr.y - 2][curr.x - 1]) {
                    q.push({curr.y - 2, curr.x - 1, curr.depth + 1});
                    visit[curr.y - 2][curr.x - 1] = true;
                }
            } if (curr.x + 1 < x) {
                if (/*map[curr.y - 1][curr.x] && map[curr.y - 2][curr.x] && */map[curr.y - 2][curr.x + 1] && !visit[curr.y - 2][curr.x + 1]) {
                    q.push({curr.y - 2, curr.x + 1, curr.depth + 1});
                    visit[curr.y - 2][curr.x + 1] = true;
                }
            }
        } if (curr.x - 2 >= 0) {
            if (curr.y - 1 >= 0) {
                if (/*map[curr.y][curr.x - 1] && map[curr.y][curr.x - 2] &&*/ map[curr.y-1][curr.x - 2] && !visit[curr.y - 1][curr.x - 2]) {
                    q.push({curr.y - 1, curr.x - 2, curr.depth + 1});
                    visit[curr.y - 1][curr.x - 2] = true;
                }
            } if (curr.y + 1 < y) {
                if (/*map[curr.y][curr.x - 1] && map[curr.y][curr.x - 2] && */map[curr.y+1][curr.x - 2] && !visit[curr.y + 1][curr.x - 2]) {
                    q.push({curr.y + 1, curr.x - 2, curr.depth + 1});
                    visit[curr.y + 1][curr.x - 2] = true;
                }
            }
        } if (curr.y + 2 < y) {
            if (curr.x - 1 >= 0) {
                if (/*map[curr.y + 1][curr.x] && map[curr.y + 2][curr.x] && */ map[curr.y + 2][curr.x - 1] && !visit[curr.y + 2][curr.x - 1]) {
                    q.push({curr.y + 2, curr.x - 1, curr.depth + 1});
                    visit[curr.y + 2][curr.x - 1] = true;
                }
            } if (curr.x + 1 < x) {
                if (/*map[curr.y + 1][curr.x] && map[curr.y + 2][curr.x] && */map[curr.y + 2][curr.x + 1] && !visit[curr.y + 2][curr.x + 1]) {
                    q.push({curr.y + 2, curr.x + 1, curr.depth + 1});
                    visit[curr.y + 2][curr.x + 1] = true;
                }
            }
        } if (curr.x + 2 < x) {
            if (curr.y - 1 >= 0) {
                if (/*map[curr.y][curr.x + 1] && map[curr.y][curr.x + 2] && */map[curr.y-1][curr.x + 2] && !visit[curr.y - 1][curr.x + 2]) {
                    q.push({curr.y - 1, curr.x + 2, curr.depth + 1});
                    visit[curr.y - 1][curr.x + 2] = true;
                }
            } if (curr.y + 1 < y) {
                if (/*map[curr.y][curr.x + 1] && map[curr.y][curr.x + 2] &&*/ map[curr.y+1][curr.x + 2] && !visit[curr.y + 1][curr.x + 2]) {
                    q.push({curr.y + 1, curr.x + 2, curr.depth + 1});
                    visit[curr.y + 1][curr.x + 2] = true;
                }
            }
        }
    }
}