#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

inline float dist(pair<float, float> p1, pair<float, float> p2)
{
	return sqrt((p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second));
}

int p[101];

int find(int n) 
{
	return (p[n] < 0) ? n : p[n] = find(p[n]);
}

void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b) return;
	p[b] = a;
}

int main()
{
	memset(p, -1, sizeof p);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<pair<float, float>> op;
	for (int i = 0; i < N; i++) {
		float x, y;
		cin >> x >> y;
		op.emplace_back(x, y);
	}
	vector<pair<float, pair<float, float>>> vec;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			vec.push_back(make_pair(dist(op[i], op[j]), make_pair(i, j)));
		}
	}

	int sum = 0;
	for (auto& el : vec) {
		if (find(el.second.first) != find(el.second.second)) {
			merge(el.second.first, el.second.second);
			sum += el.first;
		}
	}

	cout << sum;
}