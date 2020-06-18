#include <iostream>
#include <vector>
#include <algorithm>

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

vector<int> vec;

int f(int s, int e) 
{
    if (s>=e) return 0;
    if (e - s == 1) return vec[s] * vec[s];

    int st = s;
    int M = 0;
    for (int i = s; i < e; i++) {
        if (vec[i] < M) {
            st = i;
            M = vec[i];
        }
    }

    int l = st; int r = st;
    int result = max(f(s, st-1), f(st+1,e ));
    int m = vec[st], sum = vec[st];
    result = max(result, m * sum);

    while (r - l + 1 < e - s) {
        int p = l > s ? min(m, vec[l - 1]) : -100000001;
        int q = r < e - 1 ? min(m, vec[r + 1]) : -100000001;
        if (p >= q) {
            m = p;
            sum += vec[l - 1];
            l--;
        }
        else {
            m = q;
            sum += vec[r + 1];
            r++;
        }
        result = max(result, m * sum);
    }
    return result;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
   
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    
    cout << f(0, n);
}