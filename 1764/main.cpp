#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	set<string> st;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		st.insert(temp);
	}
	vector<string> vec;
	for (int i = 0; i < M; i++) {
		string temp;
		cin >> temp;
		if (st.find(temp) != st.end()) {
			vec.push_back(temp);
		}
	}
	sort(vec.begin(), vec.end());
	cout << vec.size()<<'\n';
	for (auto el : vec) {
		cout << el << '\n';
	}
}