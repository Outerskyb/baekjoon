#include <iostream>
#include <cinttypes>
#include <vector>

using namespace std;

struct room {
    int t;
    int a;
    int h;
};

int main()
{
    int n, Hatk;
    cin >> n >> Hatk;
    vector<room> vec;
    for (int i = 0; i < n; i++) {
        int t, a, h;
        cin >> t >> a >> h;
        vec.push_back({ t,a,h });
    }

    int64_t l = 0;
    int64_t h = 1e18;

    while (l + 1 < h) {
        int64_t Hmax = (l + h) / 2;
        int64_t Hcur = Hmax;
        int64_t Hatkcur = Hatk;
        bool isDead = false;

        for (int i = 0; i < n; i++) {
            if (vec[i].t == 1) {
                int h = vec[i].h;
                if((h-1) / Hatkcur > (Hcur-1)/vec[i].a){
                    isDead = true;
                    break;
                }
                Hcur -= (h-1)/Hatkcur*vec[i].a;
            }
            else {
                Hatkcur += vec[i].a;
                Hcur += vec[i].h;
                if (Hcur > Hmax) Hcur = Hmax;
            }
        }
        //cout << Hmax << " : " << ((isDead) ? 1 : 0) << '\n';
        if (isDead) l = Hmax;
        else h = Hmax;
    }
    cout << h<<'\n';
}