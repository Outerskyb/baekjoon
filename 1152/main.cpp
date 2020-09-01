#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char str[1000001];
	int count = 0;
	scanf("%[^\n]s", str);
	if (str[0] == ' ') count--;
	if (str[strlen(str) - 1] == ' ') count--;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == ' ') count++;
	}
	cout << count + 1;

}