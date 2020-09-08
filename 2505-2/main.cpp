#include<iostream>
#include<vector>
using namespace std;
void reverse_vector(vector<int> &ary, int i, int j) {
	for (int y = 1; y <= j - i + 1; y++) {
		for (int x = i; x < j - y + 1; x++) {
			int a;
			a = ary[x];
			ary[x] = ary[x + 1];
			ary[x + 1] = a;
		}
		/*for (int b = 0; b < ary.size(); b++) {
		printf("%d ", ary[b]);
		}
		printf("\n");*/
	}

}

bool is_repeat(vector<int> ary) {//정렬됬는지 확인
	int count = 0;
	for (int i = 0; i < ary.size(); i++) {
		if (ary[i] == i + 1) {
			count++;
		}
	}
	return (count == ary.size()) ? false : true;
}

int main(void) {
	int N;
	vector<int> ary;
	scanf("%d", &N);
	int n;
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		ary.push_back(n);
	}

	while (is_repeat(ary)) {
		for (int i = 0; i < ary.size(); i++) {
			if (ary[i] != i + 1) {
				for (int j = i; j < ary.size(); j++) {
					if (ary[j] == i + 1) {
						reverse_vector(ary, i, j);
						printf("%d %d\n", i + 1, j + 1);
					}
				}
			}
		}
	}
}