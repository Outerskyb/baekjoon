#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    vector<int> vec;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    long long ans = 0;
    stack<pair<int, int>> stk;
    stk.push(make_pair(vec[0], 1));
    int cnt = 1;
    for (int i = 1; i < N; i++)
    {
        if (!stk.empty()&&stk.top().first < vec[i]) {
            while (!stk.empty() && stk.top().first < vec[i]) {
                ans += stk.top().second;
                cnt -= stk.top().second;
                stk.pop();    
            }
            if (!stk.empty()&&stk.top().first == vec[i]) {
                ans += stk.top().second+(stk.size() > 1);
                stk.top().second++;
                cnt++;
            }
            else {
                ans += (stk.size() > 0);
                stk.push(make_pair(vec[i], 1));
                cnt++;
            }
        }
        else if (!stk.empty()&&stk.top().first == vec[i]) {
            ans += stk.top().second+(stk.size()>1);
            stk.top().second++;
            cnt++;
        }
        else {
            ans++;
            cnt++;
            stk.push(make_pair(vec[i],1));
        }
    }/*
    if (vec[N-2]>vec[N-1]) {
        ans += 1;
    }*/
    cout << ans;
}