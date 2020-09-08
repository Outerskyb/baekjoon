#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool map[1001][1001];
int integral_image[1001][1001];

int main()
{
	string a, b;
	cin >> a >> b;

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) map[i][j] = true;
		}
	}


	for (int i = a.size() - 1; i >= 0; i--) {
		for (int j = b.size() - 1; j >= 0; j--) {
			if(!map[i][j]) integral_image[i][j] = (integral_image[i + 1][j] > integral_image[i][j + 1]) ? integral_image[i + 1][j] : integral_image[i][j + 1];
			else integral_image[i][j] = integral_image[i + 1][j + 1] + 1;
		}
	}
	cout << integral_image[0][0];
}