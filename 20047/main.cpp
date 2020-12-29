#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct s {
    int left;
    int bias;
    int cnt;
    int mat;
    int mode;
    bool u1;
    bool u2;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string str1, str2;
    int p1, p2;
    cin >> n;
    cin >> str1 >> str2;
    cin >> p1 >> p2;

    queue<s> q;
    q.push({ 0,0,0,0,0,0,0 });
    while (!q.empty()) {
        auto left = q.front().left;
        auto bias = q.front().bias;
        auto cnt = q.front().cnt;
        auto mat = q.front().mat;
        auto mode = q.front().mode;
        auto u1 = q.front().u1;
        auto u2 = q.front().u2;
        q.pop();
        bool isCom = false;
        for (int i = left; i < n; i++) {
            //bias 庆力 l1
            if (mode == -1 && str1[i - bias] == str1[p1]) {
                bias--;
                if (cnt == 1) mode = 0;
            }
            //bias 庆力 l2
            if (mode == -1 && bias == 1 && str1[i - bias] == str1[p2]) {
                bias--;
            }
            //bias 庆力 r1
            if (mode == 1 && str2[i] == str1[p1]) {
                bias++;
                if (cnt == 1) mode = 0;
            }
            //bias 庆力 r2
            if (mode == 1 && bias == 1 && str2[i] == str1[p2]) {
                bias++;
            }
            if (!mat && str1[i - bias] == str2[i]) mat = true;
            if (str1[i - bias] != str2[i]) {
                if (cnt == 2) { isCom = true; break; }
                if (cnt == 0) {
                    //l1
                    if (str2[i] == str1[p1]) {
                        bias++;
                        cnt++;
                        q.push({ i + 1,bias,cnt,mat,-1,true,false });
                    }
                    //l2 cnt2
                    if (mat && str2[i] == str1[p2]) {
                        bias++;
                        cnt = 2;
                        q.push({ i + 1,bias,cnt,mat,-1,false,true });
                    }
                    //r2 cnt2
                    if (mat) {
                        bias--;
                        cnt = 2;
                        q.push({ i + 1,bias,cnt,mat,1,false,true });
                        q.push({ i + 1,bias, 1, mat,1,true,false });
                    }
                    //r1
                    else {
                        bias--;
                        cnt = 1;
                        q.push({ i + 1,bias ,cnt,mat,1,false,true });
                    }
                    break;

                }
                if (cnt == 1) {
                    //l1 -> l2
                    if (mode == -1 && str1[i - bias] == str1[p2]) {
                        bias++;
                        cnt = 2;
                        q.push({ i + 1,bias,cnt,mat,mode,true,true });
                    }//r1->c->l2
                    if (mode == 0 && str1[i - bias] == str1[p2]) {
                        bias++;
                        cnt = 2;
                        q.push({ i + 1,bias,cnt,mat,-1,true,true });
                    }//l1 -> c -> r2
                    else if (mode == 0) {
                        bias--;
                        cnt = 2;
                        q.push({ i + 1,bias,cnt,mat,1,true,true });
                    }
                    //r1->r2
                    if (mode == 1) {
                        bias++;
                        cnt = 2;
                        q.push({ i + 1,bias,cnt,mat,mode,true,true });
                    }
                    break;
                }
            }
        }

        if (!isCom) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}