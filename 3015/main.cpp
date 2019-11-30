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
    int cnt = 0;
    stack<int> stk;   
    stk.push(vec[0]);
    for (int i = 1; i < N; i++)
    {
        if (stk.top() < vec[i]) {
            int s = 1;
            while (!stk.empty() && stk.top() <= vec[i]) {
                cnt++;
                s++;
                if (stk.top() == vec[i]) {
                    int j = i - s;
                    while (j>=0&&vec[j] == vec[i]) {
                        cnt++, j--;
                    }
                    break;
                }
                else
                    stk.pop();
            }
            stk.push(vec[i]);
        }
        else if (stk.top() == vec[i]) {
            cnt += stk.size();
            stk.push(vec[i]);
        }
        else {
            cnt += 1;
            stk.push(vec[i]);
        }
    }
    if (stk.size() != 0) {
        cnt += stk.size() - 1;
    }

    cout << cnt;

}