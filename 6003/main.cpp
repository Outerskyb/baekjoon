#include <iostream>
#include <vector>

using namespace std;

int main(){
    using namespace std;
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<long long,long long>> vec;
    for(int i = 0; i< n;i++){
        int a,b;
        cin >> a>> b;
        vec.push_back({a,b});
    }

    int m = 978654321;
    int cow1,cow2;
    for(int i = 0; i < n;i++){
        for(int j = i + 1 ; j < n;j++){
            if((vec[i].first-vec[j].first)*(vec[i].first-vec[j].first)+(vec[i].second-vec[j].second)*(vec[i].second-vec[j].second)<m){
                m = (vec[i].first-vec[j].first)*(vec[i].first-vec[j].first)+(vec[i].second-vec[j].second)*(vec[i].second-vec[j].second);
                cow1 = i, cow2 = j;
            }
        }
    }

    cout << cow1+1 << ' ' << cow2+1;
}