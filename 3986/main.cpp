#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	stack<int> st;
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		stack<char> st;
		for (auto el : str) {
			if (st.empty() || st.top() != el)
				st.push(el);
			else
				st.pop();
		}
		ans += st.empty();
	}
	cout << ans;
}