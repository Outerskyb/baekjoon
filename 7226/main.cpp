#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;

    int ac = 0, dc = 0, in = 0;

    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        ac = dc = in = 0;
        for (int i = 0; i < k; i++) {
            char c;
            int n;
            cin >> c >> n;
            if (c == 'I') {
                if (q1.size() > q2.size() && n < q1.top()) {
                    q1 = priority_queue<int>();
                    auto temp = q2;
                    for (int i = 0; i < q2.size(); i++)
                        q1.push(temp.top()), temp.pop();
                }
                q1.push(n);
                if (q2.size() > q1.size() && n > q2.top()) {
                    q2 = priority_queue<int, vector<int>, greater<int>>();
                    auto temp = q1;
                    for (int i = 0; i < q1.size(); i++)
                        q2.push(temp.top()), temp.pop();
                }
                q2.push(n);
                ++in;
            }
            else if (n == 1 && ac + dc < in) {
                q1.pop();
                ++ac;
            }
            else if (ac + dc < in) {
                q2.pop();
                ++dc;
            }
            if (in != 0 && ac + dc == in) {
                q1 = priority_queue<int>();
                q2 = priority_queue<int, vector<int>, greater<int>>();
                in = ac = dc = 0;
            }
        }
        //원소 남은 경우
        // 1개 일 떄 q1.top == q2.top
        if (ac + dc < in) {
            cout << q1.top() << ' ' << q2.top() << '\n';
        }
        //ac+dc == in이면 비었으니 엠티
        else {
            cout << "EMPTY\n";
        }
    }
}