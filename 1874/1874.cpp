#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

int main(void) {
	int N;
	vector<int> ary;
	stack<int> stk;
	string str;

	char plus = '+';
	char minus = '-';

	scanf("%d", &N);
	int a;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		ary.push_back(a);
	}
	int current_max = 0;
	for (int i = 0; i < N; i++) {
		if (ary[i] > current_max) {
			for (int j = current_max + 1; j <= ary[i]; j++) {
				stk.push(j);
				str += plus;
			}
			current_max = ary[i];
			stk.pop();
			str += minus;
		}
		else {
			if (ary[i] == stk.top()) {
				stk.pop();
				str += minus;
			}
			else {
				printf("NO\n");
				return 0;
			}
		}
	}
	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << endl;
	}
}