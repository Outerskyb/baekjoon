#include <iostream>

int main() {
    char input[5][16] = { 0, };
    std::cin >> input[0];
    std::cin >> input[1];
    std::cin >> input[2];
    std::cin >> input[3];
    std::cin >> input[4];

    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < 5; i++) {
            if (input[i][j] != ' '&&input[i][j] != EOF&&input[i][j] != '\n'&&input[i][j]!=0) {
                std::cout << input[i][j];
            }
        }
    }
}