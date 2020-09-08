#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

set<int> thom;

void make_thom()
{
    std::vector<std::vector<int>> vec(6);
    vec[0].push_back(4),vec[0].push_back(7);
    for(int d = 1; d<6;d++){
        for(int i = 0 ; i < vec[d-1].size();i++){
            vec[d].push_back(vec[d-1][i] + 4 * pow(10,d));
            vec[d].push_back(vec[d-1][i] + 7 * pow(10,d));
        }
    }
    for(int i = 0 ; i < vec.size();i++){
        for(int j = 0 ; j < vec[i].size();j++){
            thom.insert(vec[i][j]);
        }
    }
}

int main()
{
    int N;
    cin>>N;

    make_thom();
    int ans = ((*thom.lower_bound(N))==N)?N:(*(--thom.lower_bound(N)));
    cout << ans;
}