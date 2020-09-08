#include <iostream>
#include <vector>
#include <string>

#define v(a) (a=='A')?0:((a=='C')?1:((a=='G')?2:3))

using namespace std;

int n, m;

int f(int a, int b, int c, int d) {
	if (a >= b && a >= c && a >= d) {
		cout << 'A';
		return b + c + d;
	}
	else if (b >= a && b >= c && b >= d) {
		cout << 'C';
		return a + c + d;
	}
	else if (c >= a && c >= b && c >= d) {
		cout << 'G';
		return a + b + d;
	}
	else if (d >= a && d >= b && d >= c) {
		cout << 'T';
		return a + b + c;
	}
}

int main()
{
	cin >> n >> m;

	char temp;
	scanf("%c", &temp);
	
	vector<string> vec(n);
	vector<vector<int>> count(m);

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	for (int i = 0; i < m; i++)
		count[i] = vector<int>(4);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			count[j][v(vec[i][j])]++;
		}
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cnt += f(count[i][0], count[i][1], count[i][2], count[i][3]);
	}
	cout << '\n' << cnt;

}