#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int n, l;
	cin >> n >> l;

	vector<stack<int>> st(6, stack<int>());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int s, p;
		cin >> s >> p;
		--s;
		while (!st[s].empty() && st[s].top() > p) {
			++ans, st[s].pop();
		}
		if (st[s].empty() || st[s].top() != p) {
			st[s].push(p);
			++ans;
		}
	}
	cout << ans;
}