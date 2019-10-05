#include <iostream>
#include <vector>
#define max(a,b) (((a) > (b)) ? (a) : (b))
using namespace std;

double new_length, old_length;
double left_length, right_length;

void folding(vector<int> &ary,int num) {
	if (ary[num * 2] == ary[num * 2 + 1]) {
		return;
	}
	double avr = (ary[num * 2] + ary[num * 2 + 1]) / 2.0;
	left_length = avr;
	right_length = old_length - avr;	
	new_length = max(left_length, right_length);
	for (int i = 0; i < 6; i++) {
		if (ary[i] <= left_length) {
			ary[i] = new_length - left_length + ary[i];
		}
		else {
			ary[i] = old_length - ary[i] + new_length - right_length;
		}
	}
	old_length = new_length;
}

int main() {
	int N;
	vector<int> ary;
	scanf("%d", &N);
	old_length = N;
	for (int i = 0; i < 6; i++) {
		int a;
		scanf("%d", &a);
		ary.push_back(a);
	}
	for (int i = 0; i < 3; i++) {
		folding(ary, i);
	}
	printf("%.1lf", new_length);
}