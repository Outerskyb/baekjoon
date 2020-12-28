#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int k;
    cin >> k;
    stack<int> stk;
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        if (num)stk.push(num);
        else stk.pop();
    }
    int ans = 0;
    while (!stk.empty()) {
        ans += stk.top(), stk.pop();
    }
    cout << ans;
}