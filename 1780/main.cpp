#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vec;

int one, none, zero;

void dnq(int y, int x, int n)
{
	int one_c = 0, none_c = 0;
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (vec[i][j] == 1) one_c++;
			if (vec[i][j] == -1) none_c++;
		}
	}
	if (one_c == n * n) {
		one++;
	}
	else if (none_c ==  n*n) {
		none++;
	}
	else if (one_c == 0 && none_c == 0) {
		zero++;
	}
	else {
		dnq(y, x, n / 3);
		dnq(y + (n / 3), x, n / 3);
		dnq(y, x + (n / 3), n / 3);
		dnq(y + (n / 3), x + (n / 3), n / 3);
		dnq(y + 2 * (n / 3), x, n / 3);
		dnq(y, x + 2 * (n / 3), n / 3);
		dnq(y + (n / 3), x + 2 * (n / 3), n / 3);
		dnq(y + 2 * (n / 3), x + (n / 3), n / 3);
		dnq(y + 2 * (n / 3), x + 2 * (n / 3), n / 3);
	}

}

int main()
{
	int N;
	cin >> N;

	vec = vector<vector<int>>(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			scanf("%d", &temp);
			vec[i].push_back(temp);
		}
	}
	dnq(0, 0, N);

	cout << none << '\n' << zero << '\n' << one;

}