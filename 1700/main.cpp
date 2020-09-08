#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> vec;

	for (int i = 0; i <k; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}

	vector<int> pluged;
	int  cnt = 0;
	int unplug = 0;
	for (int i = 0; i < k; i++) {
		/*printf("i : %d ", i);
		for (auto& el : pluged) printf("%d ", el);
		printf("\n");*/
		if (find(pluged.begin(), pluged.end(), vec[i]) != pluged.end());
		else if (pluged.size() < n) {
			pluged.push_back(vec[i]);
		}
		else if (i == k - 1) cnt++;
		else {
			cnt++;
			int max = 0;
			int selected = 0;
			for (auto el : pluged) {
				for (int j = i + 1; j < k; j++) {
					if (vec[j] == el) {
						if (j - i < max) break;
						max = j - i;
						selected = el;
						break;
					}
					else if (j == k - 1 && vec[j] != el) {
						selected = el;
						goto out;
					}
				}
			}
			out:
			pluged.erase(find(pluged.begin(), pluged.end(), selected));
			pluged.push_back(vec[i]);
		}
	}
	cout << cnt;
}