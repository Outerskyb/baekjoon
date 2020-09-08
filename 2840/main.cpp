#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N,K;
    cin >> N >> K;
    
    vector<char> vec(N,0);

    for(int i = 0; i < K; i++){
        int s;
        char c;
        cin >> s >> c;
        s = s%N;
        vec[s] = c;
        rotate(vec.begin(),vec.begin()+s,vec.end());
    }
    rotate(vec.begin(),vec.begin()+1,vec.end());
    for(auto it = vec.rbegin();it!=vec.rend();++it){
        cout << *it << ' ';
    }

}