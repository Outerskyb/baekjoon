#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

char		cyper[8][7]		= { "000000"
							, "001111"
							, "010011"
							, "011100"
							, "100110"
							, "101001"
							, "110101"
							, "111010" };

char*		code			 = "ABCDEFGH";

int		compare(string str) {
	for (int i = 0; i < 8; i++) 
	{
		int count = 0;
		for (int j = 0; j < 6; j++) 
		{
			if (str[j] == cyper[i][j]) 
			{
				count++;
			}
		}
		if (count == 6 || count == 5) 
		{
			return i;
		}
	}
	return -1;

}
int main() {
	int			N;
	string		input_string;
	string		answer_string;

	scanf("%d", &N);
	cin >> input_string;

	for (int i = 0; i < N; i++) {
		string			str;
		const int		w		= i * 6;

		str.push_back(input_string[w + 0]);
		str.push_back(input_string[w + 1]);
		str.push_back(input_string[w + 2]);
		str.push_back(input_string[w + 3]);
		str.push_back(input_string[w + 4]);
		str.push_back(input_string[w + 5]);

		int a = compare(str);
		if (a == -1) {
			printf("%d", i + 1);
			return 0;
		}
		else {
			answer_string.push_back(code[a]);
		}
	}
	cout <<answer_string;
	
}

/*
입력
3
001111000000011100
출력
BAD

입력
5
001111000000111111000000111111
출력
3
*/