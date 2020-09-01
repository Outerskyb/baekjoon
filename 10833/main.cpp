#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		sum += b % a;
	}
	cout << sum;
	
}