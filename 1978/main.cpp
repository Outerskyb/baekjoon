#include <iostream>
#include <vector>

using namespace std;

bool p[1001];

int main()
{
	int n;
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		vec.push_back(temp);
	}
	p[1] = true;
	for (int i = 2; i <= 1000; i++) {
		if (p[i] == true) continue;
		for (int j = i*2; j <= 1000; j+=i) {
			p[j] = true;
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (p[vec[i]] == false) {
			cnt++;
		}
	}
	cout << cnt;
	
}