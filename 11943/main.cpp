#include<iostream>

using namespace std;

int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("%d", ((a + d) < (c + b)) ? (a + d) : (b + c));
}