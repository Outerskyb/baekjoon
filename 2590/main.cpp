#include<iostream>

using namespace std;

int main() {
    int one, two, three, four, five, six;
    int panel = 0;
    int space_for_one = 0, space_for_two = 0;

    scanf("%d %d %d %d %d %d", &one, &two, &three, &four, &five, &six);

    panel += six;
    panel += five;
    panel += four;
    panel += three % 4 == 0 ? three / 4 : (three / 4) + 1;

    space_for_one += five * 11;
    space_for_one += four * 20;
    space_for_one += (three % 4) == 1 ? 27 : ((three % 4) == 2) ? 18 : (three % 4) == 3 ? 9 : 0;

    space_for_two += four * 5;
    space_for_two += (three % 4) == 1 ? 5 : (three % 4) == 2 ? (one>6) ? 2 : 3 : (three % 4) == 3 ? 1 : 0;

    if (six == 0 && four == 0 && five == 0 && three%4 == 0) {
        panel++;
        space_for_one = 36;
        space_for_two = 9;
        if (one == 0 && two == 0) {
            printf("%d", --panel);
            return 0;
        }
    }

    if (space_for_two > two) {
        space_for_one -= two * 4;
        two = 0;
    }
    else {
        space_for_one -= space_for_two * 4;
        two -= space_for_two;
    }

    if (space_for_one > one) {
        one = 0;
    }
    else {
        one -= space_for_one;
    }

    while (one != 0 || two != 0) {
        panel++;
        space_for_one = 36;
        space_for_two = 9;
        if (space_for_two > two) {
            space_for_one -= two * 4;
            two = 0;
        }
        else {
            space_for_one -= space_for_two*-4;
            two -= space_for_two;
        }

        if (space_for_one > one) {
            one = 0;
        }
        else {
            one -= space_for_one;
        }
    }

    printf("%d", panel);
}