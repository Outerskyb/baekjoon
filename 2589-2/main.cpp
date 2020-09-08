#include <iostream>
#include <queue>
#include <cstring>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int map[50][50];
bool visit[50][50];

int h, w;

struct p {
	int y;
	int x;
	int l;
};

int main()
{
	cin >> h >> w;
	for (int i = 0; i < h * w; i++) {
		char temp;
		cin >> temp;
		map[i / w][i % w] = temp == 'L';
	}
	int M = 0;
	for (int i = 0; i < h * w; i++) {
		if (map[i / w][i % w]) {
			queue<p> q;
			memset(visit, 0, sizeof visit);
			q.push({ i / w,i % w,0 });
			visit[i / w][i % w] = true;
			while (!q.empty()) {
				auto curr = q.front();
				q.pop();
				M = max(M, curr.l);
				if (curr.y > 0 && map[curr.y - 1][curr.x] && !visit[curr.y - 1][curr.x])
					q.push({ curr.y - 1,curr.x,curr.l + 1 }), visit[curr.y - 1][curr.x] = true;
				if (curr.x > 0 && map[curr.y][curr.x - 1] && !visit[curr.y][curr.x - 1])
					q.push({ curr.y, curr.x - 1,curr.l + 1 }), visit[curr.y][curr.x - 1] = true;
				if (curr.x < w - 1 && map[curr.y][curr.x + 1] && !visit[curr.y][curr.x + 1])
					q.push({ curr.y ,curr.x + 1,curr.l + 1 }), visit[curr.y][curr.x + 1] = true;
				if (curr.y < h - 1 && map[curr.y + 1][curr.x] && !visit[curr.y + 1][curr.x])
					q.push({ curr.y + 1,curr.x,curr.l + 1 }), visit[curr.y + 1][curr.x] = true;
			}
		}
	}
	cout << M;

}