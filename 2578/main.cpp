#include<iostream>

using namespace std;

int main() {
    int board[5][5];
    int number[25];
    int line_count = 0;
    int count = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    for (int i = 0; i < 25; i++) {
        scanf("%d", number + i);
    }
    while (count != 25) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == number[count])
                    board[i][j] = 0;
            }
        }
        
        for (int i = 0; i < 5; i++) {
            int check = 0;
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == 0) check++;
            }
            if (check == 5) line_count++;
            check = 0;
            for (int j = 0; j < 5; j++) {
                if (board[j][i] == 0) check++;
            }
            if (check == 5) line_count++;
        }
        if (board[2][2] == 0) {
            if (board[0][0] == 0 && board[1][1] == 0 && board[3][3] == 0 && board[4][4] == 0) line_count++;
            if (board[4][0] == 0 && board[3][1] == 0 && board[1][3] == 0 && board[0][4] == 0) line_count++;
        }
        if (line_count == 3) {
            printf("%d", count+1);
            return 1;
        }
        line_count = 0;
        count++;
    }

}