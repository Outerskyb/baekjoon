#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;

    while(T--){
        
        string str;
        cin >> str;
        stack<char> st;
        for(auto el : str){
            if(el == '(')
                st.push('(');
            else if(!st.empty())
                st.pop();
            else{
                cout << "NO\n"; goto a;
            }
        }
        if(st.empty())
            cout <<"YES\n";
        else
            cout <<"NO\n";
        a:;
    }
}