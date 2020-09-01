#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	map<int, int> mp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (mp.size() == 0 || mp.find(temp) == mp.end()) {
			mp.insert(make_pair(temp, 1));
		}
		else ++(*mp.find(temp)).second;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		
		cout << ((mp.find(temp) == mp.end()) ? 0 : (*mp.find(temp)).second)<<' ';
	}
}