#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    char prev;
    char input;
    input = getchar();
    prev = input;
     do{
        input = getchar();
        sum += (prev == input) ? 5 : 10;
        prev = input;
     } while (input == '(' || input == ')');
    printf("%d", sum);
}