#include <iostream>
#include <vector>

#define min(a,b) (((a)>(b))?(b):(a))

using namespace std;

int pmap[401][401];
int nmap[401][401];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)  
            nmap[i][j] =pmap[i][j] = ((i == j)?0:123456789);
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        nmap[b][a] = 1;
        pmap[a][b] = 1;
    }

    for (int l = 0; l < n; l++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                nmap[i][j] = min(nmap[i][j], nmap[i][l] + nmap[l][j]);
                pmap[i][j] = min(pmap[i][j], pmap[i][l] + pmap[l][j]);
            }
        }
    }

    int s;
    cin >> s;

    for (int i = 0; i < s; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (pmap[a][b] != 123456789) {
            cout << -1<<'\n';
        }else if (nmap[a][b] != 123456789) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
    
}