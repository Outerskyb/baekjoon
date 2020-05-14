#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int dp[500][30];

int N;

bool func(int n,int s) 
{
    if (dp[n][s] != -1) return dp[n][s];
    if (s > N - 1) return false;

    for (int i = s; i < N; i++) {
        
    }
}

int main() 
{
    memset(dp, -1, sizeof dp);

    
    cin >> N;
    vector<int> vec;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());

    int b;
    cin >> b;
    
    for (int i = 0; i < b; i++) {
        int num;
        cin >> num;
        cout << ((func(num,0)==true)?"Y ":"N ");
    }

}