#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> vec;
	map<string,int> mp;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		vec.push_back(str);
		mp.insert({ str,i+1 });
	}
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (str[0] <= '9') {
			cout << vec[stoi(str)-1] << '\n';
			continue;
		}
		cout << mp[str]<<'\n';
	}
}
