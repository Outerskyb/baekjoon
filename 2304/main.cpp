#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	stack<int> st;
	vector<int> vec(1001);

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		vec[a] = b;
	}

	int ans = 0;
	int max = -1;
	int max_idx = -1;
	for (int i = 0; i < 1001; i++) {
		if (vec[i] > max) {
			if(max_idx !=-1) ans += max * (i - max_idx);
			max = vec[i];
			max_idx = i;
		}
	}
	
	int max1 =-1, max_idx1 = -1;
	for (int i = 1000; i >= 0; i--) {
		if (vec[i] > max1) {
			if (max_idx1 != -1) ans += max1 * (max_idx1-i);
			max1 = vec[i];
			max_idx1 = i;
		}
	}
	ans += max1 * (max_idx1 - max_idx + 1);

	cout << ans;
}