#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> vec(N);
    set<vector<int>> st;
    for (int i = 0; i < N; i++) vec[i] = i + 1;
    do{
        vector<int> v;
        for (int j = 0; j < M; j++) {
            v.push_back(vec[j]);
        }
        st.insert(v);
    }while(next_permutation(vec.begin(), vec.end()));
    for (auto v : st) {
        for (auto el : v) {
            cout << el << ' ';
        }
        cout << '\n';
    }
}
