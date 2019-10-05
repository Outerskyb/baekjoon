#include<iostream>
#include<cstring>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int R;
		char str[100];
		cin >> R >> str;
		for (int i = 0; i<strlen(str); i++) {
			for (int j = 0; j<R; j++) {
				cout << str[i];
			}
			
		}
		printf("\n");
	}
}