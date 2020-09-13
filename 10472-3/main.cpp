#include <iostream>
#include <queue>

using namespace std;

int pos[] = { 11,23,38,89,186,308,200,464,416 };

int main()
{
    int p;
    cin >> p;
    while (p--) {
        int board = 0;
        bool visit[1024] = { 0, };
        for (int i = 0; i < 9; i++) {
            char temp;
            cin >> temp;
            board |= ((temp == '*') << i);
        }
        queue<pair<int, int>> q;
        q.push({ 0, 0 });
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (curr.first == board) {
                cout << curr.second << '\n';
                break;
            }

            for (int i = 0; i < 9; i++) {
                if (!visit[curr.first ^ pos[i]]) {
                    q.push({ curr.first ^ pos[i],curr.second+1 });
                    visit[curr.first ^ pos[i]] = true;
                }
            }
        }
    }
}