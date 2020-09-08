#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int map[1500][1500];
int p[1500][1500];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int R ,C;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < C; j++) {
			map[i][j] = str[j];
		}
	}


}