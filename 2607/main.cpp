#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int alphabet[100][26] = { 0, }; 

void parse(string str, int num) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] < 'A') {
			return;
		}
		alphabet[num][str[i] - 'A']++;
	}
}
int compare(int num) {
	int positive_bulge = 0;
	int negative_bulge = 0;
	for (int i = 0; i < 26; i++) {
		 ((alphabet[0][i] - alphabet[num][i])>0) ?
			positive_bulge += (alphabet[0][i] - alphabet[num][i]):
			negative_bulge -= (alphabet[0][i] - alphabet[num][i]);
	}
	return (positive_bulge <= 1 && negative_bulge <= 1) ? 1 : 0;
}

int main() {
    int n;
	int count = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		parse(str, i);
	}
	for (int i = 1; i < n; i++) {
		count += compare(i);
	}
	printf("%d", count);
}
#include <iostream>
#include <string>

using namespace std;

bool compareWord(string, string);

int main(void)
{
    string word[100];
    int wordNum;
    int similNum = 0;

    cin >> wordNum;

    for (int i = 0; i < wordNum; ++i)
        cin >> word[i];

    for (int i = 1; i < wordNum; ++i)
        if (compareWord(word[0], word[i]))
            similNum++;

    cout << similNum;

    return 0;
}

bool compareWord(string word1, string word2)
{
    int alphabet[2][26] = { 0, };
    int gap[2] = { 0 };

    for (int i = 0; word1[i] != 0; ++i)
        alphabet[0][word1[i] - 'A']++;
    for (int i = 0; word2[i] != 0; ++i)
        alphabet[1][word2[i] - 'A']++;

    for (int i = 0; i < 26; ++i)
    {
        if (alphabet[0][i] - alphabet[1][i] > 0)
            gap[0] += alphabet[0][i] - alphabet[1][i];
        else if (alphabet[1][i] - alphabet[0][i] > 0)
            gap[1] += alphabet[1][i] - alphabet[0][i];
    }

    return gap[0] < 2 && gap[1] < 2;
}
/*
test_case
input
5
AB
AA
A
BC
CA
output
4

input
4
AB
A
BB
CB
P
output
3
input
26
A
B
C
D
E
F
G
H
I
J
K
L
M
N
O
P
Q
R
S
T
U
V
W
X
Y
Z
output
25

*/