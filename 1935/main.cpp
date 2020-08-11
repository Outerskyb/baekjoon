#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string str;
    cin >>str;

    vector<int> vec(n);
    for(int i = 0;  i <n;i++){
        cin >> vec[i];
    }

    stack<double> st;
    for(auto el : str){
        switch (el){
        case '+':
        {
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            st.push(b+a);
        }
            break;
        case '*':
        {
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            st.push(a*b);
        }
            break;
        case '-':
        {
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            st.push(b-a);
        }
            break;
        case '/':
        {
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            st.push(b/a);
        }
            break;
        
        default:
            st.push(vec[el-'A']);
            break;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout<<st.top();
}