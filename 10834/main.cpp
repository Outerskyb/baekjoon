#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int M;
	cin >> M;
	bool cw = true;
	int bee = 1;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		bee = bee / a * b;
		if (c) cw = !cw;
	}
	cout << ((cw) ? 0 : 1) << ' ' << bee;
}