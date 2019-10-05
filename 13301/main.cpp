#include<iostream>

using namespace std;

long long int fibo[80] = { 1,1 };
 
void get_fibo() {
	for (int i = 2; i < 80; i++) {
		fibo[i] = fibo[i - 2] + fibo[i - 1];
	}
	return;
}
 
int main() {
	int N;

	get_fibo();

	scanf("%d", &N);
	printf("%lld ", fibo[N+1]*2);
	
}