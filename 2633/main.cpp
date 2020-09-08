#include <iostream>
#include <vector>

using namespace std;

int map[100][100];

int main()
{
    int x1, y1, x2, y2, n;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    x1--, y1--, x2--, y2--;
    for (int i = 0; i < n; i++) {
        int px1, py1, px2, py2, px3, py3, px4, py4;
        cin >> px1 >> py1 >> px2 >> py2 >> px3 >> py3 >> px4 >> py4;
        px1--, py1--, px2--, py2--, px3--, py3--, px4--, py4--;
        for (int y = py1; y <= py2; y++) {
            for (int x = px1; x <= px4; x++) {
                map[y][x] = 1;
            }
            if (y > py4) {
                for (int x = px4; x < px3; x++) {
                    map[y][x] = 1;
                }
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cout << map[i][j];
        }
        cout << '\n';;
    }

}