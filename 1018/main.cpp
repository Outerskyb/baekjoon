#include <iostream>

using namespace std;
int n, m;
char map[50][50];

int check(int s,int S) {
	int o = 0, e = 0;
	for (int i = s; i < s+8; i++) {
		for (int j = S; j < S+8; j++) {
			if ((i + j) % 2 == map[i][j] % 2) {
				o++;
			}
			else {
				e++;
			}
		}
	}
	return (e > o) ? o : e;
}


int main()
{
	cin >> n >> m;

	char temp;
	scanf("%c", &temp);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &map[i][j]);
		}
		char temp;
		scanf("%c", &temp);
	}
	int min = 65;
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			min = (min>check(i,j))?check(i,j):min;
		}
	}
	cout << min;
}