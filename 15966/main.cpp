#include <iostream>
#include <cstring>
#include <map>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    map<int, int> mp;
    int arr[1000000];
    int cnt[1000000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i], cnt[i] = 1;;
    }

    int M = 1;
    mp.insert({ arr[0],1 });
    for (int i = 0; i < n; i++) {
        auto it = mp.find(arr[i] - 1);
        if (it != mp.end()) {           
            cnt[i] = cnt[(*it).second] + 1;
            M = max(M, cnt[i]);
        }
        mp.insert({ arr[i],i });
    }
    cout << M;
}