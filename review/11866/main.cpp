#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i);

    int cnt = 0;
    cout << "<";
    while (!q.empty())
    {
        if (++cnt == k) {
            cout << q.front();
            q.pop();
            if (!q.empty()) cout << ", ";
            cnt = 0;
        }
        else {
            q.push(q.front());
            q.pop();
        }
    }
    cout << ">";
}