#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() 
{
    while (1) {
        string s;
        stack<int> stk;
        getline(cin, s);

        if (s == ".") break;

        for (auto el : s) {
            if (el == '(' || el == '[' || el == '{')
                stk.push(el);
            else if (el == ')' || el == '}' || el == ']') {
                if (el < 50) el -= 1; else el -= 2;
                if (!stk.empty() && stk.top() == el)
                    stk.pop();
                else if (stk.empty()) {
                    stk.push(1);
                    break;
                }
                else {
                    break;
                }
            }
        }
        if (stk.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    
}