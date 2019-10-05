#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	while (N--) {
		string a;
		stack<int> stk;
		cin >> a;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] == '(') {
				stk.push('(');
			}
			else {
				if (stk.empty()) {
					printf("NO\n");
					goto out;
				}
				else {
					stk.pop();
				}
			}
		}
		if (stk.empty()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	out:
		; // end of while
	}
}