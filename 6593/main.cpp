#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct fong {
	int l;
	int r;
	int c;
	int level;
};

int map[31][31][31];
bool visit[31][31][31];

int L, R, C;
int stl, str, stc;
int dsl, dsr, dsc;
queue<fong> que;

void bfs()
{
	while (!que.empty()) {
		fong curr = que.front();
		que.pop();
		if (visit[curr.l][curr.r][curr.c]) continue;
		visit[curr.l][curr.r][curr.c] = true;
		if (curr.l == dsl && curr.r == dsr && curr.c == dsc) {
			printf("Escaped in %d minute(s).\n", curr.level); return;
		}
		if (curr.l + 1 < L && map[curr.l + 1][curr.r][curr.c] && !visit[curr.l + 1][curr.r][curr.c]) {
			que.push({ curr.l + 1,curr.r,curr.c ,curr.level + 1 });
		}
		if (curr.l - 1 >= 0 && map[curr.l - 1][curr.r][curr.c] && !visit[curr.l - 1][curr.r][curr.c]) {
			que.push({ curr.l - 1,curr.r,curr.c ,curr.level + 1 });
		}
		if (curr.r + 1 < R && map[curr.l][curr.r + 1][curr.c] && !visit[curr.l][curr.r + 1][curr.c]) {
			que.push({ curr.l ,curr.r + 1,curr.c ,curr.level + 1 });
		}
		if (curr.r - 1 >= 0 && map[curr.l][curr.r - 1][curr.c] && !visit[curr.l][curr.r - 1][curr.c]) {
			que.push({ curr.l ,curr.r - 1,curr.c ,curr.level + 1 });
		}
		if (curr.c + 1 < C && map[curr.l][curr.r][curr.c + 1] && !visit[curr.l][curr.r][curr.c + 1]) {
			que.push({ curr.l ,curr.r,curr.c + 1,curr.level + 1 });
		}
		if (curr.c - 1 >= 0 && map[curr.l][curr.r][curr.c - 1] && !visit[curr.l][curr.r][curr.c - 1]) {
			que.push({ curr.l ,curr.r,curr.c - 1,curr.level + 1 });
		}
	}
	printf("Trapped!\n");
}

int main()
{
	while (1)
	{
		memset(map, 0, 31 * 31 * 31);
		memset(visit, 0, 31 * 31 * 31);
		que = queue<fong>();
		cin >> L >> R >> C;
		char temp;
		scanf("%c", &temp);
		if (L == 0 && R == 0 && C == 0) break;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					char temp;
					scanf("%c", &temp);
					if (temp == 'S') stl = i, str = j, stc = k;
					if (temp == 'E') dsl = i, dsr = j, dsc = k;
					if (temp == '#') map[i][j][k] = 0;
					else map[i][j][k] = 1;
				}
				char temp;
				scanf("%c", &temp);
			}
			char temp;
			scanf("%c", &temp);
		}
		que.push({ stl,str,stc,0 });
		bfs();
	}
}