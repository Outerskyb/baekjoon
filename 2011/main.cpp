#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> fibo(5001);
void fib() {
	fibo[0] = 1;
	fibo[1] = 1;
	for (int i = 2; i <= 5000; i++) {
		fibo[i] = (fibo[i - 1] % 1000000 + fibo[i - 2] % 1000000) % 1000000;
	}
}

int main()
{
		fib();
		string str;
		cin >> str;
		if ( str[0] == '0') { cout << 0; return 0; }

		const int sz = str.size();
		vector<int> nums;
		int cnt = 0;
		for (int i = 0; i < sz - 1; i++) {
			if (str[i] >= '3') nums.push_back(cnt + 1), cnt = 0;
			else if (str[i] == '1') cnt++;
			else if (str[i] == '2' && str[i + 1] < '7') cnt++;
			else if (str[i] == '0') nums.push_back(cnt - 1), cnt = 0;
			else nums.push_back(cnt + 1), cnt = 0;
		}
		if (str[sz - 1] == '0') nums.push_back(cnt);
		else nums.push_back(cnt + 1);

		int ans = 1;
		for (auto& num : nums) {
			ans *= fibo[num] % 1000000;
			ans %= 1000000;
		}
		cout << ( ans % 1000000);
	
}