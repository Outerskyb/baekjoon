#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

struct a {
	int n;
	int d;
};

queue<a> q;
bool v[100000];
int main()
{
	int N, T, G;
	cin >> N >> T >> G;

	q.push({ N,0 });
	while (!q.empty()) 
	{
		a c = q.front();
		q.pop();
		if (v[c.n]) continue;
		if (c.n == G) {
			printf("%d", c.d); return 0;
		}
		if (c.d >= T) { printf("ANG"); return 0; }
		v[c.n] = true;
		if (c.n + 1 < 100000 && !v[c.n + 1]) {
			q.push({ c.n + 1,c.d + 1 });
		}
		if (c.n * 2 < 100000 && !v[c.n * 2]) {
			q.push({ c.n * 2 - (int)pow(10,(int)log10(c.n*2)),c.d + 1 });
		}
	}
	printf("ANG");
}