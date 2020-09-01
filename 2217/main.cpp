#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	std::vector<int> vec(n);
	
	for (int i = 0; i < n; i++) cin >> vec[i];
	
	sort(vec.begin(), vec.end());

	int max = -1;
	for (int i = 0; i < n; i++) max = (max > vec[i] * (n - i)) ? max : vec[i] * (n - i);
	
	cout << max;
}