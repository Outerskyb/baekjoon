#include <iostream>

using namespace std;

char map[6562][6562];

void carpet(int y, int x, int n, char ch)
{
	if (n == 1) map[y][x] = ch;
	else if (ch == '*') {
		carpet(y, x, n / 3, '*');
		carpet(y + n / 3, x, n / 3, '*');
		carpet(y, x + n / 3, n / 3, '*');
		carpet(y + n / 3, x + n / 3, n / 3, ' ');
		carpet(y + 2 * n / 3, x, n / 3, '*');
		carpet(y, x + 2 * n / 3, n / 3, '*');
		carpet(y + 2 * n / 3, x + n /3, n / 3, '*');
		carpet(y + n / 3, x + 2 * n / 3, n / 3, '*');
		carpet(y + 2 * n / 3, x + 2 * n / 3, n / 3, '*');
	}
	else {
		carpet(y, x, n / 3, ' ');
		carpet(y + n / 3, x, n / 3, ' ');
		carpet(y, x + n / 3, n / 3, ' ');
		carpet(y + n / 3, x + n / 3, n / 3, ' ');
		carpet(y + 2 * n / 3, x, n / 3, ' ');
		carpet(y, x + 2 * n / 3, n / 3, ' ');
		carpet(y + 2 * n / 3, x + n / 3, n / 3, ' ');
		carpet(y + n / 3, x + 2 * n / 3, n / 3, ' ');
		carpet(y + 2 * n / 3, x + 2 * n / 3, n / 3, ' ');
	}
}

int main()
{
	int N;
	cin >> N;
	carpet(0, 0, N, '*');
	for (int i = 0; i < N; i++) {
		printf("%s\n", map[i]);
	}
}