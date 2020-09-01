#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a, b;
		cin >> a >> b;
		vector<pair<int, int>> vec;
		vec.push_back({ a,b });
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			vec.push_back({ a,b });
		}
		cin >> a >> b;
		vec.push_back({ a,b });
		int map[102][102];
		for (int i = 0; i < vec.size(); i++) {
			for (int j = 0; j < vec.size(); j++) {
				if (i == j) map[i][i] = 123456789;
				else map[i][j] = (abs(vec[i].first - vec[j].first) + abs(vec[i].second - vec[j].second)>1000)?123456789:1;
			}
		}

		
		for (int k = 0; k < n + 2; k++)
			for (int i = 0; i < n + 2; i++)
				for (int j = 0; j < n + 2; j++)
					map[i][j] = (map[i][j] > map[i][k] + map[k][j]) ? map[i][k] + map[k][j] : map[i][j];

		cout << ((map[0][n + 1] == 123456789) ? "bad" : "happy")<<'\n';
	}

}