#include <iostream>
#include <cmath>

using namespace std;

bool is_han(int num) 
{
	if (num < 100) return true;
	int prev = num % 10;
	num /= 10;
	int diff = num % 10 - prev;
	prev = num % 10;
	num /= 10;
	while (num > 0) {
		if (diff != num % 10 - prev) return false;
		prev = num % 10;
		num /= 10;
	}
	return true;
}

int main()
{
	int N;
	cin >> N;
	int count = 0;
	for (int i = 1; i <= N; i++) {
		count += is_han(i);
	}
	cout<< count;
	return 0;
}