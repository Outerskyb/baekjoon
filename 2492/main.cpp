#include <bits/stdc++.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

using namespace std;

struct s
{
    int y;
    int x;
    int m;
};

int main()
{
    ios::sync_with_stdio(false);
    int n, m, t, k;
    cin >> n >> m >> t >> k;
    vector<s> vec;
    for (int i = 0; i < t; i++){
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b, 0});
    }

    int M = 1;
    for (int i = 0; i < t; i++){
        for(int h = 0 -k; h <= k;h++){
            for(int w = -k ; w <= k;w++){
                int cnt = 0;
                int top = max(vec[i].y+h,vec[i].y-(k-h));
                int bottom = min(vec[i].y+h,vec[i].y-(k-h));
                int left = max(vec[i].x+w,vec[i].x-(k-w));
                int right = min(vec[i].y+w,vec[i].y-(k-w));
                for(int j = 0 ; j < t; j++)
                    if(vec[j].y<=top&&vec[j].y>=bottom&&vec[j].x>=left&&vec[j].x<=right)
                        ++cnt;
                    
                M = max(M,cnt);
            }
        }
    }
    cout << M;
}