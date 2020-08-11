#include <iostream>
#include <vector>
#include <cstring>

#define max(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int L;
    cin >> L;
    vector<pair<int,int>> vec;
    int ans = 0;

    for (int i = 0; i < L; i++)
    {
        int jewel[1000];
        int dp[1000]={0};

        int n;
        cin >> n;
        int M = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> jewel[j];
        }
        dp[0] = jewel[0];
        int st = 0;
        int sst = 0; int end = n+1;
        for (int j = 1; j < n; j++)
        {
            if (dp[j - 1] < 0)
            {
                dp[j] = jewel[j];
                st = j;
            }
            else
            {
                dp[j] = dp[j - 1] + jewel[j];
            }
            if (dp[j] > M)
            {
                M = dp[j];
                sst = st;
                end = j;
            }else if(dp[j] == M && j-st<end-sst){
                sst = st;
                end = j;
            }
        }
        if(M != 0) 
            vec.push_back({sst,end});
        ans += M;
    }
    cout << ans<<'\n';
    for(auto el : vec){
        cout << el.first + 1<< ' ' << el.second + 1 <<'\n';
    }
}