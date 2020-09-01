#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> vec;
	set<int> st;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
		st.insert(temp);
	}
	map<int, int> vec2;
	int cnt = -1;
	for (auto el : st) vec2.insert({ el, ++cnt });
	for (auto el : vec) {
		cout << vec2[el] << ' ';
	}
	return 0;

}