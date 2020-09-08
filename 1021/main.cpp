#include<iostream>
#define min(a,b) (((a)<(b))?(a):(b))
#include<list>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    cin >> N >> M;
    list<int> vec;
    for(int i = 0; i < N; i++) vec.push_back(i+1);
    int ans = 0;
    for(int i = 0; i < M; i++){
        int num;
        cin >> num;
        auto it = vec.begin();
        for(int j = 0; j< vec.size();++it,++j){
            if(*it == num){
                int move =  min(j, vec.size()-j);
                ans+=move;
                for(int k = 0;  k< move;k++){
                    if(move == j){
                        int a  = vec.front();
                        vec.pop_front();
                        vec.push_back(a);
                    }else{
                        int a = vec.back();
                        vec.pop_back();
                        vec.push_front(a);
                    }
                }
                vec.erase(vec.begin());
                break;
            }
        }
    }
    cout << ans;
}
