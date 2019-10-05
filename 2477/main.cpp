#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int K;
    int vec[6];
    int way[6];
    int mv = 0, mh = 0;

    scanf("%d", &K);
    for (int i = 0; i < 6; i++) {
        scanf("%d", &way[i]);
        scanf("%d", &vec[i]);
        if ((way[i] == 1 || way[i] == 2) && vec[i] > mh) mh = vec[i];
        if ((way[i] == 3 || way[i] == 4) && vec[i] > mv) mv = vec[i];
    }

    int point;
    for (int i = 0; i < 6; i++) {
        if (way[i] == 3 && way[(i + 1) % 6] == 1 && way[(i + 2) % 6] == 3) {
            point = i;
        }
        if (way[i] == 1 && way[(i + 1) % 6] == 4 && way[(i + 2) % 6] == 1) {
            point = i;
        }
        if (way[i] == 4 && way[(i + 1) % 6] == 2 && way[(i + 2) % 6] == 4) {
            point = i;
        }
        if (way[i] == 2 && way[(i + 1) % 6] == 3 && way[(i + 2) % 6] == 2) {
            point = i;
        }
    }

    printf("%d", (mv*mh - vec[(point + 1) % 6] * vec[(point + 2) % 6]) * K);

}