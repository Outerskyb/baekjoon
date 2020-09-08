#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool f[1000];

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	vector<pair<int, int>> vec;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int d, w;
		cin >> d >> w;
		vec.push_back(make_pair(w, d));
	}

	sort(vec.rbegin(), vec.rend());

	int sum = 0;

	for (int i = 0; i < N; i++) {
		if (!f[vec[i].second]) {
			f[vec[i].second] = true;
			sum += vec[i].first;
		}
		else {
			int a;
			for (a = 1; a < vec[i].second ; a++) {
				if (!f[vec[i].second - a]) {
					f[vec[i].second - a] = true;
					sum += vec[i].first;
					break;
				}
			}
		}
	}
	cout << sum;
}