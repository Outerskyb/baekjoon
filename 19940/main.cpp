#include <iostream>
#include <queue>

using namespace std;

struct s{
    int min;
    int b[5];
};



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> m;
        bool visit[10000000]={1,0};
        queue<s> q;
        q.push({0,{0,0,0,0,0}});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(curr.min == m){
                for(const auto& el: curr.b){
                    cout << el << ' ';
                }
                cout << '\n';
                break;
            }
            if(curr.min<m+120&&!visit[curr.min + 60]){
                visit[curr.min+60] = true;
                q.push({curr.min+60,{curr.b[0]+1,curr.b[1],curr.b[2],curr.b[3],curr.b[4]}});
            }
            if(!visit[curr.min + 10]){
                visit[curr.min+10] = true;
                q.push({curr.min+10,{curr.b[0],curr.b[1]+1,curr.b[2],curr.b[3],curr.b[4]}});
            }
            if(curr.min>10&&!visit[curr.min - 10]){
                visit[curr.min-10] = true;
                q.push({curr.min-10,{curr.b[0],curr.b[1],curr.b[2]+1,curr.b[3],curr.b[4]}});
            }
            if(!visit[curr.min + 1]){
                visit[curr.min+1] = true;
                q.push({curr.min+1,{curr.b[0],curr.b[1],curr.b[2],curr.b[3]+1,curr.b[4]}});
            }
            if(curr.min>1&&!visit[curr.min - 1]){
                visit[curr.min-1] = true;
                q.push({curr.min-1,{curr.b[0],curr.b[1],curr.b[2],curr.b[3],curr.b[4]+1}});
            }
        }
    }
}