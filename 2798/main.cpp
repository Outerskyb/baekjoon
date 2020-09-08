#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n,  m;
	cin >> n >> m;

	vector<int> vec;

	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		vec.push_back(temp);
		
	}
	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (vec[i] + vec[j] + vec[k] > ans && vec[i] + vec[j] + vec[k] <= m) {
					ans = vec[i] + vec[j] + vec[k];
				}
			}
		}
	}
	cout << ans;
}