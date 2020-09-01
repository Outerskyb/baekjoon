#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<int> q1;
	priority_queue<int,vector<int>,greater<int>> q2;

	int bc = 0, sc = 0, in = 0;

	int T;
	cin >> T;
	while (T--) {
		int k;
		cin >> k;
		q1 = priority_queue<int>();
		q2 = priority_queue<int, vector<int>, greater<int>>();
		in = bc = sc = 0;
		for (int i = 0; i < k; i++) {
			char c;
			int n;
			cin >> c >> n;
			if (c == 'I') {
				q1.push(n);
				q2.push(n);
				++in;
			}
			else if (n == 1 && bc + sc < in) {
				q1.pop();
				++bc;
			}
			else if (bc + sc < in) {
				q2.pop();
				++sc;
			}
			if (in != 0 && bc + sc == in) {
				q1 = priority_queue<int>();
				q2 = priority_queue<int, vector<int>, greater<int>>();
				in = bc = sc = 0;
			}
		}
		if (bc + sc < in ) {
			cout << q1.top() << ' ' << q2.top() << '\n';
		}
		else {
			cout << "EMPTY\n";
		}
	}
}
/*
2
8
I 1
I 2
I 3
D -1
D -1
D -1
D -1
I 0
4
I 1
D 1
D -1
D 1
*/