#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;

	int fibo[100] = { 1,1, };
	for (int i = 2; i < 100; i++) 
		fibo[i] = fibo[i - 1] + fibo[i - 2];

	vector<int> vip;
	vip.push_back(0);
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		vip.push_back(temp);
	}
	vip.push_back(n+1);

	int ans = 1;
	for (int i = 1; i < vip.size(); i++) {
		ans *= fibo[vip[i] - vip[i - 1] - 1];
	}
	cout << ans;
	
}

/*
123
213
132 3

1234
1243
1324
2134
2143 5

*/