#include <iostream>
#include <string>

using namespace std;
int N;
char map[50][50];

int check() {
	int max = 0;
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (map[i][j - 1] == map[i][j]) {
				cnt++;
			}
			else {
				max = (max > cnt) ? max : cnt;
				cnt = 1;
			}
		}
		max = (max > cnt) ? max : cnt;
		cnt = 1;
	}
	for (int j = 0; j < N; j++) {
		for (int i = 1; i < N; i++) {
			if (map[i - 1][j] == map[i][j]) {
				cnt++;
			}
			else {
				max = (max > cnt) ? max : cnt;
				cnt = 1;
			}
		}
		max = (max > cnt) ? max : cnt;
		cnt = 1;
	}
	return max;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (map[i][j] != map[i][j + 1]) {
				char temp = map[i][j];
				map[i][j] = map[i][j + 1];
				map[i][j + 1] = temp;

				max = (max > check()) ? max : check();

				temp = map[i][j];
				map[i][j] = map[i][j + 1];
				map[i][j + 1] = temp;
			}
		}
	}
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - 1; i++) {
			if (map[i][j] != map[i + 1][j]) {
				char temp = map[i][j];
				map[i][j] = map[i + 1][j];
				map[i + 1][j] = temp;

				max = (max > check()) ? max : check();

				temp = map[i][j];
				map[i][j] = map[i + 1][j];
				map[i + 1][j] = temp;
			}
		}
	}

	cout << max;
}