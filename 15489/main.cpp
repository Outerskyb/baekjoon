#include <iostream>

using namespace std;

int t[31][31];
int main()
{
	int r, c, w;
	cin >> r >> c >> w;
	r--, c--;
	for (int i = 0; i <= 30; i++) {
		t[i][0] = t[i][i] = 1;
	}
	for (int i = 2; i <= 30; i++) {
		for (int j = 1; j <= i - 1; j++) {
			t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
		}
	}

	int sum = 0;
	for (int i = 0; i < w; i++) {
		for (int j = c; j <= c + i; j++) {
			sum += t[r + i][j];
		}
	}
	cout << sum;
}