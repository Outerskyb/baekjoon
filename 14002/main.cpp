#include <iostream>
#include <cinttypes>
#include <vector>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int arr[1000], dp[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i], dp[i] = 1;

    int M = 1;
    for (int i = 1; i < n; i++)
        for (int j = 0; j <= i; j++) 
            if (arr[i] > arr[j]) 
                dp[i] = max(dp[i], dp[j] + 1), M = max(M, dp[i]);

    cout << M << '\n';

    int curr = 1200;
    vector<int> vec;
    for (int i = n - 1; i >= 0; i--) 
        if (dp[i] == M && arr[i] < curr) 
            vec.push_back(arr[i]),
            --M, curr = arr[i];
       
    for (auto it = vec.rbegin(); it != vec.rend(); it++)
        cout << *it << ' ';
}