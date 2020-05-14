#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;

    while (T--) {
        int k;
        cin >> k;
        multiset<int> mst;
        for (int i = 0; i < k; i++) {
            char c; int n;
            cin >> c >> n;

            if (c == 'I') {
                mst.insert(n);
            }
            else if (mst.size() == 0) continue;
            else if (n == 1) {
                mst.erase(--mst.end());
            }
            else {
                mst.erase(mst.begin());
            }
        }
        if (mst.size() == 0) cout << "EMPTY\n";
        else cout << *(--mst.end()) << ' ' << *mst.begin() << '\n';
    }
}