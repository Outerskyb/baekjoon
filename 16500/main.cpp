#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int dp[101];

int main()
{
	ios::sync_with_stdio(false);
	string s;
	int n;
	cin >> s >> n;

	vector<string> vec;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		vec.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		if (s.size() >= vec[i].size() && s.substr(0, vec[i].size()) == vec[i])
			dp[vec[i].size()] = 1;
	}
	for (int j = 0; j < s.size(); j++) {
		if (!dp[j]) continue;
		for (int i = 0; i < n; i++) {
			if (s.size() >= vec[i].size() && s.substr(j, vec[i].size()) == vec[i]) {
				dp[j + vec[i].size()] = 1;
				break;
			}
		}
	}

	cout << dp[s.size()]<<'\n';
}