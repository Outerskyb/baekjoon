#include <iostream>
#include <string>
#include <stack>
#include <fstream>

using namespace std;

struct ordered_pair {
    int count;
    int pos;
};

std::string solution(string input, string bomb) {
    stack<ordered_pair> stk;
    int bomb_cnt = 0;
    const int bomb_size = bomb.size();

    //input.

    if (bomb_size == 1) {
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == bomb[0]) {
                input.erase(i, 1);
                i -= 1;
            }
        }
        goto lbl;
    }

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == bomb[0]) {
            stk.push({ 1,i });
            bomb_cnt = 1;
            continue;
        }
        if (bomb_cnt != 0 && input[i] != bomb[bomb_cnt]) {
            stk.pop();
            bomb_cnt = (stk.empty()) ? 0 : stk.top().count;
        }
        else if (input[i] == bomb[bomb_cnt]) {
            stk.top().count++;
            bomb_cnt++;
        }
        if (bomb_cnt == bomb_size) {
            input.erase(stk.top().pos, stk.top().count);
            i -= stk.top().count;
            stk.pop();
            bomb_cnt = (stk.empty()) ? 0 : stk.top().count;
        }
    }
lbl:
    if (input.size() == 0) {
        return "FRULA";

    }
    return input;
}
std::string name = "eksplozija.";
std::string a = "a";
std::string b = "b";
std::string c = "c";
std::string in = "in.";
std::string out = "out.";
int main() {
    for (int i = 1; i <= 10; i++) {

        std::string num = to_string(i);
        std::string input;
        std::string bomb;
        std::string answer;
        ifstream inf(name + in + num + a);
        ifstream of(name + out + num + a);
        inf >> input;
        inf >> bomb;
        of >> answer;

        std::string sol = solution(input, bomb);

        if (answer != sol) {
            printf("%d a\n", i);
        }
        inf.close();
        of.close();

        inf.open(name + in + num + b);
        of.open(name + out + num + b);
        inf >> input;
        inf >> bomb;
        of >> answer;
        sol = solution(input, bomb);
        if (answer != sol) {
            printf("%d b\n", i);
        }
        inf.close();
        of.close();

        inf.open(name + in + num + c);
        of.open(name + out + num + c);
        inf >> input;
        inf >> bomb;
        of >> answer;
        sol = solution(input, bomb);
        if (answer != sol) {
            printf("%d c\n", i);
        }
        inf.close();
        of.close();
    }
}