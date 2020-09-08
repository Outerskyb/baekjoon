#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> ans;
	vector<int> vec;
	vector<int> visit(n,false);
	vector<int> finish(n, false);

	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp - 1 == i) ans.push_back(temp - 1), visit[i] = true, finish[i] = true;
		vec.push_back(temp-1);
	}
	
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			int curr = i;
			vector<int> temp;
			while (!visit[curr]) {
				visit[curr] = true;
				temp.push_back(curr);
				curr = vec[curr];
			}
			if (!finish[curr]) {
				ans.push_back(curr);
				for (int temp = vec[curr]; temp != curr;temp = vec[temp]) {
					ans.push_back(temp);
				}
			}
			for (auto& el : temp) {
				finish[el] = true;

			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size()<<'\n';
	for (auto& el : ans) cout << el +1<< '\n';
}