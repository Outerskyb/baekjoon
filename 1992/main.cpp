#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

char map[64][64] = { 0, };

string get_code(int left, int top, int length) {
    int sum = 0;
    string result;
    for (int i = top; i < top + length; i++) {
        for (int j = left; j < left + length; j++) {
            if(map[i][j]=='1') sum += 1;
        }
    }
    if (sum == length*length) {
        result += "1";
    }
    else if (sum == 0) {
        result += "0";
    }
    else {
        if (length != 1) {
            result += "(";
            result += get_code(left, top, length / 2);
            result += get_code(left + length / 2, top, length / 2);
            result += get_code(left, top + length / 2, length / 2);
            result += get_code(left + length / 2, top + length / 2, length / 2);
            result += ")";
        }
        else {
            result += "(";
            result += map[left][top];
            result += map[left + 1][top];
            result += map[left][top + 1];
            result += map[left + 1][top + 1];
            result += ")";
        }
    }
    return result;
}


int main() {
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%s", map[i]);        
    }
    if (N == 1) {
        cout << map[0][0];
        exit(0);
    }
   cout<< get_code(0, 0, N);
}