#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	int arr[26]={ 0 };
	cin >> a;
	for (int i = 0; i < a.size(); i++)
		++arr[a[i]-'a'];
	for (auto el : arr) cout << el << ' ';
}