#include <iostream>

using namespace std;

bool map[101][101];

void color(int x, int y, int w, int h) {
	for (int j = y; j < h; j++)
		for (int i = x; i < w; i++)
			map[j][i] = true;

}

int main()
{
	for (int i = 0; i < 4; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		color(a, b, c, d);
	}
	int cnt = 0;
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			if (map[i][j]) cnt++;

	cout << cnt;
}