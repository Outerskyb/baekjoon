#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> vec(N);
    for (int i = 0; i < N; i++)
        cin >> vec[i];

    int64_t ans = 0;

    stack<int> st;
    st.push(vec[0]);

    for (int i = 1; i < N; i++) {
        if (vec[i] < st.top()) {
            st.push(vec[i]);
        } else {
            while (!st.empty() && vec[i] >= st.top()) {
                st.pop();
                ans += st.size();
            }
            st.push(vec[i]);
        }
    }
    while (!st.empty()) {
        st.pop();
        ans += st.size();
    }
    cout << ans;
}