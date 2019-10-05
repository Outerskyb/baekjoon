#include <iostream>
#include <string>

int main() {
    std::string input;
    bool previous_left;
    int stack_size = 0;
    int answer = 0;
    std::cin >> input;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(') {
            stack_size++;
            previous_left = true;
        }
        else {
            stack_size--;
            answer += (previous_left)?stack_size:1; 
            previous_left = false;
        }
    }
    std::cout << answer;
}