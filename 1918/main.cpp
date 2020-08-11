#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    stack<char> st;
    string str;
    string result;

    cin >> str;

    for(auto c : str){
        switch (c)
        {
        case '(':
            st.push(c);
            break;
        case ')':
            while(st.top()!='('){
                cout <<st.top();
                st.pop();
            }
            st.pop();
            break;
        case '+':
        case '-':
            if(!st.empty() && st.top() != '('){
                while(!st.empty() && st.top() != '(')
                    cout << st.top() , st.pop();
            }
            st.push(c);
            break;
        case '/':
        case '*':
            if(!st.empty() && st.top()!='('&&st.top()!='+'&&st.top()!='-'){
                cout <<st.top(); st.pop();
            }
            st.push(c);
            break;
        default:
            cout << c;
            break;
        }
    }

    while(!st.empty())
        cout <<st.top() , st.pop();
}