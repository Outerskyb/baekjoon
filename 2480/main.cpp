#include<iostream>

using namespace std;
#define max(a,b) (((a)>(b))?(a):(b))
int main() {
	int a,b,c;
	scanf("%d %d %d", &a, &b, &c);
	((a == b) && (b == c)) ?printf("%d", 10000 + c * 1000):(!(a^b) || !(b^c)) ? printf("%d", 1000 + b * 100) : !(a^c) ? printf("%d", a * 100+1000):printf("%d",max(max(a,b),c)*100);
}