#include<stdio.h>

int main(void) {
	int t, sum = 0;
	int N;
	scanf("%d", &N);
	while (N--) {
		scanf("%1d", &t);
		sum += t;
	}
	printf("%d", sum);
}