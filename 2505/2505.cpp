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
	int count = 0;
	int n;
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		ary.push_back(n);
	}

	while (is_repeat(ary)) {
		vector<int> slice;//연속적이지 않은, 단절된 숫자 위치 저장하는 벡터
		int prev = ary[0];
		for (int i = 0; i < N; i++) {
			if (ary[i] != prev + 1 && ary[i] != prev - 1) {
				if (i != 0) slice.push_back(i - 1);
				slice.push_back(i);
			}
			prev = ary[i];
		}
		for (int i = 0; i < slice.size(); i++) {
			for (int j = i; j < slice.size(); j++) {
				if (ary[slice[i]] - 1 == ary[slice[j]] && ary[slice[j] + 1] == ary[slice[j]] - 1) {//ex  4(i)325(j)6
					printf("1%d %d\n", slice[i] + 1, slice[j]);
					count++;
					if (count == 2) {
						return 0;
					}
					reverse_vector(ary, slice[i], slice[j] - 1);//432
					goto out;
				}
			}
			if (i != slice.size()-1&& ary[slice[i]] == N &&ary[ary.size() - 1] == slice[i] + 1) {//12348765
				reverse_vector(ary, slice[i], ary.size() - 1);
				printf("2%d %d\n", slice[i] + 1, ary.size());
				count++;
				if (count == 2) {
					return 0;
				}
			}
		}
	out:
		if (ary[0] == N&&ary[ary.size() - 1] == 1) {
			reverse_vector(ary, 0, N - 1);
			printf("3%d %d\n", 1, N);
			count++;
			if (count == 2) {
				return 0;
			}
		}
		slice.clear();
		prev = ary[0];
		for (int i = 0; i < N; i++) {
			if (ary[i] != prev + 1 && ary[i] != prev - 1) {
				if (i != 0) slice.push_back(i - 1);
				slice.push_back(i);
			}
			prev = ary[i];
		}
		for (int i = 0; i < slice.size(); i++) {
			for (int j = i; j < slice.size(); j++) {
				if (ary[slice[i]] + 1 == ary[slice[j]] &&(slice[j] == N - 1||ary[slice[j] + 1] == ary[slice[j]] + 1)) {//124356
					printf("4%d %d\n", slice[i] + 1, slice[j]);
					count++;
					if (count == 2) {
						return 0;
					}
					reverse_vector(ary, slice[i], slice[j] - 1);
					goto outa;
				}
			}
		}
	outa:;
		if (ary[slice[slice.size() - 1]] == 1) {
			reverse_vector(ary, slice[slice.size() - 1], N - 1);
			printf("5%d %d\n", slice[slice.size() - 1]+1, N);
			count++;
			if (count == 2) {
				return 0;
			}
		}
	}
}