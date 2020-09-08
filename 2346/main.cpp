#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int N;
    cin >> N;

    deque<pair<int,int>> dq;
    for(int i = 0 ; i < N; i++){
        int temp;
        cin >> temp;
        dq.push_back({i+1,temp});
    }
    
    for(int i = 0 ; i < N;i++){
        int move = dq[0].second;
        cout << dq[0].first << ' ';
        dq.pop_front();
        if(dq.empty()) break;
        if(move>0){
            for(int j = 0 ; j < move-1;j++){
                auto a = dq.front();
                dq.pop_front();
                dq.push_back(a);
            }
        }else{
            move = -1*move;
            for(int j = 0 ; j < move;j++){
                auto a = dq.back();
                dq.pop_back();
                dq.push_front(a);
            }
        }
    }
}