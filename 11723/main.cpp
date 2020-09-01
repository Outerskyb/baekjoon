#include <iostream>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int set = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		if (a[0] == 'a'&&a[1] == 'l'){
			set = 2097151;
		}else if (a[0] == 'e') {
			set = 0;
		}else {
			int b;
			cin >> b;
			switch (a[0]) {
			case 'a':
				set |= (1 << b);
				break;
			case 'r':
				set &= ~(1 << b);
				break;
			case 'c':
				if (set == (set & ~(1 << b))) {
					cout << "0\n";
				}
				else {
					cout << "1\n";
				}
				break;
			case 't':
				set ^= (1 << b);
			}
			
				
		}

	}
}