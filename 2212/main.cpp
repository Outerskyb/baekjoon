#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;

	if (k >= n) {
		cout << 0;
		return 0;
	}

	set<int> st;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		st.insert(temp);
	}

	vector<int> vec;
	int prev = *st.begin();
	for (auto it = ++st.begin(); it != st.end(); ++it) {
		vec.push_back(*it - prev);
		prev = *it;
	}
	sort(vec.begin(), vec.end());
	int sum = 0;
	for (int i = 0; i < n-k; i++) {
		sum += vec[i] / 2;
	}
	cout << sum;
	

}