#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sum ;
vector<int> vec;

long long sp(vector<int> v) {
    if (v.size() == 1) return 0;
    long long e = 0, o = 0;
    vector<int> ve, vo;
    for (int i = 0; i < v.size(); i++) {
        if (i % 2) e += v[i], ve.push_back(v[i]);
        else o += v[i], vo.push_back(v[i]);
    }
    return e * o + sp(ve) + sp(vo);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vec = vector<int>(n);
    for (int i = 0; i < n; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    
    cout << sp(vec);
}