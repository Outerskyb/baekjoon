#include <iostream>

using namespace std;


int main()
{
	int n, k;
	cin >> n >> k;
	int tri[31][31];
	for (int i = 0; i < 31; i++) {
		tri[i][0] = tri[i][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
		}
	}
	cout << tri[n-1][k-1];
}