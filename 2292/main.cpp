#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> vec;
	
	int curr = 1;
	int cnt = 1;
	while (1) {
		if (curr > 1000000000) break;
		vec.push_back(curr);
		curr += cnt * 6;
		cnt++;
	}
	
	for (int i = 0; i < vec.size(); i++) {
		if (N <= vec[i]) {
			cout << i+1<<'\n';
			return 0;
		}
	}
	cout << 18258;
	
}