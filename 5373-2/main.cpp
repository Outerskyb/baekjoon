#include <iostream>
#include <string>

using namespace std;

char cube[6][3][3];

void cube_init()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[0][i][j] = 'w';
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[1][i][j] = 'r';
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[2][i][j] = 'b';
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[3][i][j] = 'o';
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[4][i][j] = 'g';
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[5][i][j] = 'y';
        }
    }
}

void rotf(int l, bool cw)
{
    int temp[3] = { 0, };

    temp[0] = cube[l][0][0];
    temp[1] = cube[l][0][1];
    temp[2] = cube[l][0][2];

    if (!cw) {
        cube[l][0][0] = cube[l][0][2];
        cube[l][0][1] = cube[l][1][2];
        cube[l][0][2] = cube[l][2][2];
        cube[l][1][2] = cube[l][2][1];
        cube[l][2][2] = cube[l][2][0];
        cube[l][2][1] = cube[l][1][0];
        cube[l][2][0] = temp[0];
        cube[l][1][0] = temp[1];
    }
    else {
        cube[l][0][0] = cube[l][2][0];
        cube[l][0][1] = cube[l][1][0];
        cube[l][0][2] = temp[0];
        cube[l][1][0] = cube[l][2][1];
        cube[l][2][0] = cube[l][2][2];
        cube[l][2][1] = cube[l][1][2];
        cube[l][2][2] = temp[2];
        cube[l][1][2] = temp[1];
    }
}

void rots(bool cw, char& a1, char& a2, char& a3, char& b1, char& b2, char& b3, char& c1, char& c2, char& c3, char& d1, char& d2, char& d3) {
    int temp[3] = { a1,a2,a3 };

    if (cw) {
        a1 = d1, a2 = d2, a3 = d3, d1 = c1, d2 = c2, d3 = c3, c1 = b1, c2 = b2, c3 = b3, b1 = temp[0], b2 = temp[1], b3 = temp[2];
    }
    else {
        a1 = b1, a2 = b2, a3 = b3, b1 = c1, b2 = c2, b3 = c3, c1 = d1, c2 = d2, c3 = d3, d1 = temp[0], d2 = temp[1], d3 = temp[2];
    }
}

void U(bool cw)
{
    rotf(0, cw);
    rots(cw,
        cube[4][0][2], cube[4][0][1], cube[4][0][0],
        cube[3][0][2], cube[3][0][1], cube[3][0][0],
        cube[2][0][2], cube[2][0][1], cube[2][0][0],
        cube[1][0][2], cube[1][0][1], cube[1][0][0]);
}
void D(bool cw)
{
    rotf(5, cw);
    rots(cw,
        cube[1][2][2], cube[1][2][1], cube[1][2][0],
        cube[2][2][2], cube[2][2][1], cube[2][2][0],
        cube[3][2][2], cube[3][2][1], cube[3][2][0],
        cube[4][2][2], cube[4][2][1], cube[4][2][0]);

}
void F(bool cw)
{
    rotf(1, cw);
    rots(cw,
        cube[0][2][0], cube[0][2][1], cube[0][2][2],
        cube[2][0][0], cube[2][1][0], cube[2][2][0],
        cube[5][0][2], cube[5][0][1], cube[5][0][0],
        cube[4][2][2], cube[4][1][2], cube[4][0][2]);
}
void B(bool cw)
{
    rotf(3, cw);
    rots(cw,
        cube[4][2][0], cube[4][1][0], cube[4][0][0],
        cube[5][2][2], cube[5][2][1], cube[5][2][0],
        cube[2][0][2], cube[2][1][2], cube[2][2][2],
        cube[0][0][0], cube[0][0][1], cube[0][0][2]);
}
void L(bool cw)
{
    rotf(4, cw);
    rots(cw,
        cube[3][2][2], cube[3][1][2], cube[3][0][2],
        cube[0][0][0], cube[0][1][0], cube[0][2][0],
        cube[1][0][0], cube[1][1][0], cube[1][2][0],
        cube[5][0][0], cube[5][1][0], cube[5][2][0]);
}
void R(bool cw)
{
    rotf(2, cw);
    rots(cw,
        cube[0][2][2], cube[0][1][2], cube[0][0][2],
        cube[3][0][0], cube[3][1][0], cube[3][2][0],
        cube[5][2][2], cube[5][1][2], cube[5][0][2],
        cube[1][2][2], cube[1][1][2], cube[1][0][2]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cube_init();

        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            if (str[0] == 'U') {
                U(str[1] == '+');
            }
            if (str[0] == 'D') {
                D(str[1] == '+');
            }
            if (str[0] == 'F') {
                F(str[1] == '+');
            }
            if (str[0] == 'B') {
                B(str[1] == '+');
            }
            if (str[0] == 'L') {
                L(str[1] == '+');
            }
            if (str[0] == 'R') {
                R(str[1] == '+');
            }
        }

        cout << cube[0][0][0] << cube[0][0][1] << cube[0][0][2] << '\n';
        cout << cube[0][1][0] << cube[0][1][1] << cube[0][1][2] << '\n';
        cout << cube[0][2][0] << cube[0][2][1] << cube[0][2][2] << '\n';
    }

}
