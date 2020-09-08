#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


struct s {
	vector<int> vec;
	int l;
};

bool vecsame(vector<int> v1, vector<int> v2) {
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}

int numvec(vector<int> vec) {
	int ans = 0;
	for (int i = 0; i < vec.size(); i++) {
		ans += vec[i] * pow(10, i);
	}
	return ans;
}

int main() 
{
	int n, k;
	cin >> n >> k;

	vector<int> ori(n);
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		cin >> ori[i];
		ans[i] = i + 1;
	}
	queue<s> q;
	
	q.push({ ori, 0 });

	map<int, bool> visit;
	
	while (!q.empty()){
		auto curr = q.front();
		q.pop();
		visit[numvec(curr.vec)] = true;
		if (vecsame(curr.vec, ans)) {
			cout << curr.l;
			return 0;
		}
		for (int i = 0; i < n - k+1; i++) {
			vector<int> vec2 = curr.vec;
			reverse(vec2.begin() + i, vec2.begin() + i + k);
			if(!visit[numvec(vec2)])
				q.push({ vec2,curr.l + 1 });
		}
	}
	cout << -1;
}