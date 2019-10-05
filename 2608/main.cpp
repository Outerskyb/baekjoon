#include <iostream>
#include <string>
using namespace std;



string itoR(int num) {
	string roman;
	if (num >= 1000) {
		int a = num / 1000;
		switch (a) {
		case 1:
			roman.push_back('M');
			break;
		case 2:
			roman.push_back('M');
			roman.push_back('M');
			break;
		case 3:
			roman.push_back('M');
			roman.push_back('M');
			roman.push_back('M');
			break;
		
		}
		num -= (num / 1000) * 1000;
	}if (num >= 100) {
		int a = num / 100;
		switch (a) {
		case 1:
			roman.push_back('C');
			break;
		case 2:
			roman.push_back('C');
			roman.push_back('C');
			break;
		case 3:
			roman.push_back('C');
			roman.push_back('C');
			roman.push_back('C');
			break;
		case 4:
			roman.push_back('C');
			roman.push_back('D');
			break;
		case 5:
			roman.push_back('D');
			break;
		case 6:
			roman.push_back('D');
			roman.push_back('C');
			break;
		case 7:
			roman.push_back('D');
			roman.push_back('C');
			roman.push_back('C');
			break;
		case 8:
			roman.push_back('D');
			roman.push_back('C');
			roman.push_back('C');
			roman.push_back('C');
			break;
		case 9:
			roman.push_back('C');
			roman.push_back('M');
			break;
		}
		num -= (num / 100)*100;
	}
	if (num >= 10) {
		int a = num / 10;
		switch (a) {
		case 1:
			roman.push_back('X');
			break;
		case 2:
			roman.push_back('X');
			roman.push_back('X');
			break;
		case 3:
			roman.push_back('X');
			roman.push_back('X');
			roman.push_back('X');
			break;
		case 4:
			roman.push_back('X');
			roman.push_back('L');
			break;
		case 5:
			roman.push_back('L');
			break;
		case 6:
			roman.push_back('L');
			roman.push_back('X');
			break;
		case 7:
			roman.push_back('L');
			roman.push_back('X');
			roman.push_back('X');
			break;
		case 8:
			roman.push_back('L');
			roman.push_back('X');
			roman.push_back('X');
			roman.push_back('X');
			break;
		case 9:
			roman.push_back('X');
			roman.push_back('C');
			break;
		}
		num -= (num / 10) * 10;
	}
	switch (num) {
	case 1:
		roman.push_back('I');
		break;
	case 2:
		roman.push_back('I');
		roman.push_back('I');
		break;
	case 3:
		roman.push_back('I');
		roman.push_back('I');
		roman.push_back('I');
		break;
	case 4:
		roman.push_back('I');
		roman.push_back('V');
		break;
	case 5:
		roman.push_back('V');
		break;
	case 6:
		roman.push_back('V');
		roman.push_back('I');
		break;
	case 7:
		roman.push_back('V');
		roman.push_back('I');
		roman.push_back('I');
		break;
	case 8:
		roman.push_back('V');
		roman.push_back('I');
		roman.push_back('I');
		roman.push_back('I');
		break;
	case 9:
		roman.push_back('I');
		roman.push_back('X');
		break;
	}
	return roman;
}

int Rtoi(string roman) {

	for (int i = 0; i < 4000; i++) {
		if (roman == itoR(i)) {
			return i;
		}
	}
}

int main() {
	string input1, input2;
	cin >> input1 >> input2;
	cout << Rtoi(input1) + Rtoi(input2) << '\n' << itoR(Rtoi(input1) + Rtoi(input2));
	
}