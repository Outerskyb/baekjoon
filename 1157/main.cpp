#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	vector<int>count(26, 0);
	for (auto& c : str) {
		count[(c > 'Z') ? c - 'a' : c - 'A']++;
	}
	int max = 0, max_idx = 0, max2 = 0, max2_idx = 0;
	for (int i = 0; i < 26; i++) {
		if (max <= count[i]) {
			max2 = max;
			max2_idx = max2_idx;
			max_idx = i;
			max = count[i];
		}
	}
	printf("%c", (max == max2) ? '?' : 'A' + max_idx);
}