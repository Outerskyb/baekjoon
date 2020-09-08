#include <iostream>

using namespace std;

int w, b;
int map[128][128];
void dq(int y, int x, int n)
{
	if (n == 1) {
		if (map[y][x] == 0) w++;
		else b++;
		return;
	}
	int sum = 0;
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			sum += map[i][j];
		}
	}
	if (sum == n * n) {
		b++;
		return;
	}
	else if (sum == 0) {
		w++;
		return;
	}
	else {
		dq(y, x, n / 2);
		dq(y + n / 2, x, n / 2);
		dq(y, x + n / 2, n / 2);
		dq(y + n / 2, x + n / 2, n / 2);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	dq(0, 0, n);
	cout << w << '\n' << b;

	return 0;
}