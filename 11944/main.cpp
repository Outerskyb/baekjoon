#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int N, M;
	char str[8064] = { 0, };
	char num[] = "1234";
	scanf("%d %d", &N, &M);
	int d = (N > 1000) ? 4 : (N > 100) ? 3 : (N > 10) ? 2 : 1;
	for (int i = 0; i < N; i++) {
		sprintf(num, "%d", N);
		strcat(str, num);
	}
	for (int i = 0; i < (((d*N) >(M)) ? M : N*d); i++) {
		printf("%c", str[i]);
	}
}