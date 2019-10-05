#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int			main() {
	vector<int>		ary(9);
	int				sum = 0;
	int				not1, not2;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &ary[i]);
		sum += ary[i];
	}
	sum -= 100;
	sort(ary.begin(), ary.end());
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if ((ary[i] + ary[j]) == sum) {
				not1 = i;
				not2 = j;
				break;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (i != not1&&i != not2) {
			printf("%d\n", ary[i]);
		}
	}
}