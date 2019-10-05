#include <iostream>

using namespace std;

int in[8];

int main()
{
	int cnt = 0, prev = 0;
	for (int i = 0; i < 8; i++) {
		scanf("%d", &in[i]);
		if (in[i] == prev + 1) cnt++;
		if (in[i] == prev - 1) cnt--;
		prev = in[i];
	}
	if (cnt == 8) cout << "ascending";
	else if (cnt == -7&&in[0]==8) cout << "descending";
	else  cout << "mixed";
}