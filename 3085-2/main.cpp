#include <iostream>

#define MAX(a,b) (((a)>(b))?(a):(b))

using namespace std;

int n;
char map[50][50];

int check()
{
	int score[50][50] = { 0, };
	int score2[50][50] = { 0, };
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (map[i][j - 1] == map[i][j]) {
				score[i][j] = score[i][j - 1] + 1;
				if (score[i][j] > max)
					max = score[i][j];
			}
		}
	}
	for (int j = 0; j < n; j++) {
		for (int i = 1; i < n; i++) {
			if (map[i - 1][j] == map[i][j]) {
				score2[i][j] = score2[i-1][j] + 1;
				max = MAX(max, score2[i][j]);
			}
		}
	}
	return max;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ans = 0;
	cin>>n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	ans = check();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			char temp = map[i][j];
			map[i][j] = map[i][j + 1];
			map[i][j + 1] = temp;

			ans = MAX(check(), ans);
			temp = map[i][j];
			map[i][j] = map[i][j + 1];
			map[i][j + 1] = temp;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n; j++) {
			char temp = map[i][j];
			map[i][j] = map[i + 1][j];
			map[i + 1][j] = temp;

			ans = MAX(check(), ans);
			temp = map[i][j];
			map[i][j] = map[i + 1][j];
			map[i + 1][j] = temp;
		}
	}
	cout << ans+1;

}