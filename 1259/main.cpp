#include <iostream>
#include <string>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1) {
		string str;
		cin >> str;
		if (str.size() == 1 && str[0] == '0') break;
		bool isp = true;
		for (int i = 0; i < str.size() / 2; i++) {
			if (str[i] != str[str.size() - i - 1]) {
				isp = false;
				break;
			}
		}
		cout << ((isp) ? "yes\n" : "no\n");

	}
}