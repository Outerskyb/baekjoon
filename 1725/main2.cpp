#include <iostream>
#include <vector>
#include <stack>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int main()
{
    int n;
    cin >> n;
    int M = 0 ;
    stack<int> st;
    vector<int> vec(n);
    for(int i = 0 ; i  < n;i++){
        cin >>vec[i];

    }
    for(int i = 0 ; i < n ; i++){
        int cnt = 1;
        while(!st.empty() && vec[i] <= st.top()){
            cnt = i - st.top() - 1;
            if(st.size() == 1) cnt = i;
            M = max(M,cnt*st.top());
            st.pop();
        }
        st.push(i);        
    }

    int cnt = 1;
    while(!st.empty()){
        if(st.size() == 1) cnt = n;
        M = max(M,cnt*st.top());
        st.pop();
        cnt++;
    }
    cout << M;
}