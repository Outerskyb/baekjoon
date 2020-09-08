#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	queue<int> que;

	while (N--) {
		string str;
		cin >> str;
		if (str == "push") {
			int temp;
			cin >> temp;
			que.push(temp);
		}
		if (str == "pop") {
			if (que.empty()) cout << -1 << '\n';
			else cout<<que.front()<<'\n',que.pop();
		}
		if (str == "size") {
			cout << que.size() << '\n';
		}
		if (str == "empty") {
			cout << int(que.empty()) << '\n';
		}
		if (str == "front") {
			if (que.empty()) cout << -1 << '\n';
			else cout << que.front() << '\n';
		}
		if (str == "back") {
			if (que.empty()) cout << -1 << '\n';
			else cout << que.back()<<'\n';
		}
	}
}