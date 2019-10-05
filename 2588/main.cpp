#include<iostream>

using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n%d\n%d\n%d", a*(b - ((b / 100) * 100 + ((b - (b / 100) * 100) / 10) * 10)), a*((b - (b / 100) * 100) / 10), a*(b / 100),a*b);
}