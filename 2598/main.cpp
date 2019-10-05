#include<iostream>

#include<unordered_set>
#include<string>

using namespace std;

typedef struct tower {
    string dice4;
    string dice3;
    string dice2;
    string dice1;
    char top;

    tower() {
        dice1 = string(4,' ');
        dice2 = string(4, ' ');
        dice3 = string(4, ' ');
        dice4 = string(4, ' ');
    }

}tower;

unordered_set<tower> set;

void prosess() {

}

int main() {
    string dice1, dice2, dice3, dice4;
    cin >> dice1 >> dice2 >> dice3 >> dice4;

    

}