#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(void) {
	int N;
	string a;
	stack<int> stk;
	cin >> a;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '(') {
			stk.push('(');
		}
		else if (a[i] == '[') {
			stk.push('[');
		}
	}
	if (stk.empty()) {
		printf("YES\n");
	}
	else {
		printf("0\n");
	}
}
