#include<iostream>
#include<vector>

using namespace std;
void swap(vector<int> &ary, int b, int e) {
	int temp = ary[e];
	int i;
	for(i = e; i > b; i--) {
		ary[i] = ary[i-1];
	}
	ary[i] = temp;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<int> step(n);
	vector<int> ary;
	for (int i = 0; i < n; i++) {
		ary.push_back(i + 1);
		scanf("%d", &step[i]);
	}
	for (int i = 0; i < n; i++) {
		swap(ary, i - step[i], i);
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", ary[i]);
	}
}