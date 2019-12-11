#include <iostream>
#include <vector>
#include <unordered_set>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    ++n;
    vector<int> vec(n);
    vector<unordered_set<int>> el(n);
    for (int i = 0; i < n; i++) vec[i] = i, el[i].insert(i);
    for (int i = 0; i < m; i++) {
        int o, a, b;
        cin >> o >> a >> b;
        if (o == 0) {
            if (a == b||vec[a]==vec[b]) continue;
            int t = vec[b];
            for (auto element : el[t]) {
                el[vec[a]].insert(element);
                vec[element] = vec[a];
            }
            el[t] = unordered_set<int>();
        }
        else {
            cout << ((vec[a] == vec[b]) ? "yes\n" : "no\n");
        }
    }
}

/*
16 18
0 0 1
0 1 2
0 2 3

0 4 5
0 5 6
0 6 7
0 6 6
0 8 9
0 9 10
0 10 11

0 1 6
0 5 10

1 3 8
1 3 11
1 1 11
1 7 8
1 7 10
1 6 2
*/