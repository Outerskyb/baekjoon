#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int M,N,K;
bool map[101][101];
bool visit[101][101];

void color(int a,int b, int c, int d){
    for(int j = b ; j <d;j++)
        for(int i = a; i < c; i++)
            map[j][i] = true;
}

int cnt = 0;
void dfs(int y, int x)
{
	visit[y][x] = true;
	cnt++;
	if (y + 1 < M && !map[y + 1][x] && !visit[y + 1][x]) {
		dfs(y + 1, x);
	}
	if (y - 1 >= 0 && !map[y - 1][x] && !visit[y - 1][x]) {
		dfs(y - 1, x);
	}
	if (x + 1 < N && !map[y][x + 1] && !visit[y][x + 1]) {
		dfs(y, x + 1);
	}
	if (x - 1 >= 0 && !map[y][x - 1] && !visit[y][x - 1]) {
		dfs(y, x - 1 );
    }
}

int main()
{
    cin >> M >> N >> K;
    for(int i = 0 ; i < K; i++){
        int x,y,a,b;
        scanf("%d %d %d %d", &x, &y , &a, &b);
        color(x,y,a,b);
    }
    int ccnt = 0 ;
    vector<int> vec;
    for(int i = 0 ; i < M ; i ++){
        for(int j  = 0 ; j < N;j++){
            if(!visit[i][j]&&!map[i][j]){
                cnt = 0;
                dfs(i,j);
                vec.push_back(cnt);
                ccnt++;
            }
        }
    }
    sort(vec.begin(),vec.end());
    cout<<ccnt<<'\n';
    for(auto& el : vec) cout << el << ' ';
}