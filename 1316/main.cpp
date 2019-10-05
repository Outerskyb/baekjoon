#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

bool af[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<string> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}

	int cnt = 0;
	for (auto& str : vec) {
		memset(af, 0, sizeof af);
		af[str[0] - 'a'] = true;
		for (int i = 1; i < str.size(); i++) {
			if (af[str[i] - 'a'] && str[i - 1] != str[i]) {
				cnt++;
				break;
			}
			else if (str[i - 1] != str[i]) {
				af[str[i] - 'a'] = true;
			}
		}
	}
	cout << N - cnt;
}