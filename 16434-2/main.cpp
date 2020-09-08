#include <iostream>
#include <cinttypes>
#include <vector>

using namespace std;

struct room{
    int t;
    int a;
    int h;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, Hatk;
    cin >> n >> Hatk;

    vector<room> vec;

    for(int i = 0 ; i < n ; i++){
        int t,a,h;
        cin >> t >> a >> h;
        vec.push_back({t,a,h});
    }

}