#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int p[1001];

int find(int n) {
	return (p[n] < 0) ? n : p[n] = find(p[n]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	p[b] = (a == b) ? p[b] : a;
}

int main()
{
	memset(p, -1, sizeof p);
	vector<pair<int, pair<int, int>>> vec;
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec.push_back(make_pair(c, make_pair(a, b)));
	}

	sort(vec.begin(), vec.end());

	int sum = 0;
	for (auto& el : vec) {
		if (find(el.second.first) != find(el.second.second)) {
			merge(el.second.first, el.second.second);
			sum += el.first;
		}
	}
	cout << sum;
}