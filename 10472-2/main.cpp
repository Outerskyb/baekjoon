#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct s {
    bool board[3][3];
    int level;
};

bool check(bool(*board)[3], bool(*now)[3]) {
    for (int i = 0; i < 9; i++) {
        if (board[i / 3][i % 3] != now[i / 3][i % 3]) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        bool board[3][3];
        for (int i = 0; i < 9; i++) {
            char temp;
            cin >> temp;
            board[i / 3][i % 3] = (temp == '*');
        }
        queue<s> q;
        s pr;
        memset(pr.board, 0, 9), pr.level = 0;
        q.push(pr);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (check(board, curr.board)) {
                cout << curr.level << '\n';
                break;
            }

            {
                s temp;
                memcpy_s((bool*)temp.board, 9, (bool*)curr.board, 9), temp.level = curr.level + 1;
                temp.board[0][0] = !temp.board[0][0];
                temp.board[0][1] = !temp.board[0][1];
                temp.board[1][0] = !temp.board[1][0];
                q.push(temp);
            }
            {
                s temp;
                memcpy_s((bool*)temp.board, 9, (bool*)curr.board, 9), temp.level = curr.level + 1;
                temp.board[0][0] = !temp.board[0][0];
                temp.board[0][1] = !temp.board[0][1];
                temp.board[1][1] = !temp.board[1][1];
                temp.board[0][2] = !temp.board[0][2];
                q.push(temp);
            }
            {//3
                s temp;
                memcpy_s((bool*)temp.board, 9, (bool*)curr.board, 9), temp.level = curr.level + 1;
                temp.board[0][1] = !temp.board[0][1];
                temp.board[0][2] = !temp.board[0][2];
                temp.board[1][2] = !temp.board[1][2];
                q.push(temp);
            }
            {//4
                s temp;
                memcpy_s((bool*)temp.board, 9, (bool*)curr.board, 9), temp.level = curr.level + 1;
                temp.board[0][0] = !temp.board[0][0];
                temp.board[1][0] = !temp.board[1][0];
                temp.board[1][1] = !temp.board[1][1];
                temp.board[2][0] = !temp.board[2][0];
                q.push(temp);
            }
            {
                s temp;
                memcpy_s((bool*)temp.board, 9, (bool*)curr.board, 9), temp.level = curr.level + 1;
                temp.board[0][1] = !temp.board[0][1];
                temp.board[1][0] = !temp.board[1][0];
                temp.board[1][1] = !temp.board[1][1];
                temp.board[1][2] = !temp.board[1][2];
                temp.board[2][1] = !temp.board[2][1];
                q.push(temp);
            }
            {//6
                s temp;
                memcpy_s((bool*)temp.board, 9, (bool*)curr.board, 9), temp.level = curr.level + 1;
                temp.board[0][2] = !temp.board[0][2];
                temp.board[1][1] = !temp.board[1][1];
                temp.board[1][2] = !temp.board[1][2];
                temp.board[2][2] = !temp.board[2][2];
                q.push(temp);
            }
            {//7
                s temp;
                
                memcpy_s((bool*)temp.board, 9, (bool*)curr.board, 9), temp.level = curr.level + 1;
                temp.board[1][0] = !temp.board[1][0];
                temp.board[2][0] = !temp.board[2][0];
                temp.board[2][1] = !temp.board[2][1];
                q.push(temp);
            }
            {//8
                s temp;
                memcpy_s((bool*)temp.board, 9, (bool*)curr.board, 9), temp.level = curr.level + 1;
                temp.board[1][1] = !temp.board[1][1];
                temp.board[2][0] = !temp.board[2][0];
                temp.board[2][1] = !temp.board[2][1];
                temp.board[2][2] = !temp.board[2][2];
                q.push(temp);
            }
            {
                s temp;
                memcpy_s((bool*)temp.board, 9, (bool*)curr.board, 9), temp.level = curr.level + 1;
                temp.board[1][2] = !temp.board[1][2];
                temp.board[2][1] = !temp.board[2][1];
                temp.board[2][2] = !temp.board[2][2];
                q.push(temp);
            }
        }
    }
}