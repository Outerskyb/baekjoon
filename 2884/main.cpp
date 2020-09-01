#include <iostream>

using namespace std;

int main()
{
	int H, M;
	cin >> H >> M;
	if (M < 45) H -= 1;
	cout << ((H ) < 0 ? 23 : H ) << ' ' << ((M - 45) < 0 ? M + 15 : M - 45);
}