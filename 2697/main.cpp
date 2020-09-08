#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		string str;
		cin >> str;

		if (next_permutation(str.begin(), str.end())) cout << str;
		else cout << "BIGGEST";
		cout << '\n';
	}
}