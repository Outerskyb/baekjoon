#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int map[1000][1000];
bool visit[1000][1000];
pair<int, int> dir4[] = { {0,1},{-1,0},{0,-1},{1,0} };
int n, m;

int main()
{
	
	int hx, hy;
	int ex, ey;
	cin >> n >> m >> hx >> hy >> ex >> ey;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}