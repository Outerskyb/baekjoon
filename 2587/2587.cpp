#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> ary(5);
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> ary[i];
		sum += ary[i];
	}
	sort(ary.begin(), ary.end());
	printf("%d\n%d", sum/5, ary[2]);
	
}