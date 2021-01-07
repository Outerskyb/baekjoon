#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int maxtree[262144];
int mintree[262144];

int s = 1;

void construct() {
    for (int i = s; i >= 1; i--) {
        maxtree[i] = max(maxtree[i * 2], maxtree[i * 2 + 1]);
        mintree[i] = min(mintree[i * 2], mintree[i * 2 + 1]);
    }
}

void max_update(int pos, int num) {
    pos += s;
    maxtree[pos] = num;
    while (pos > 1) {
        pos /= 2;
        maxtree[pos] = max(maxtree[pos * 2], maxtree[pos * 2 + 1]);
    }
}
void min_update(int pos, int num) {
    pos += s;
    mintree[pos] = num;
    while (pos > 1) {
        pos /= 2;
        mintree[pos] = min(mintree[pos * 2], mintree[pos * 2 + 1]);
    }
}

int get_max(int l, int r, int i, int nl, int nr) {
    if (nl > r || nr < l) return -1;
    if (nl >= l && nr <= r) return maxtree[i];
    int mid = (nl + nr) / 2;
    return max(get_max(l, r, i * 2, nl, mid), get_max(l, r, i * 2 + 1, mid + 1, nr));
}

int get_min(int l, int r, int i, int nl, int nr) {
    if (nl > r || nr < l) return 1000000005;   
    if (nl >= l && nr <= r) return mintree[i];
    int mid = (nl + nr) / 2;
    return min(get_min(l, r, i * 2, nl, mid), get_min(l, r, i * 2 + 1, mid + 1, nr));
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, m;
    scanf("%d %d", &n, &m);// cin >> n >> m;
    while (s < n)s *= 2;
    memset(mintree, 126, sizeof mintree);
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d",&temp);
        maxtree[i + s] = temp;
        mintree[i + s] = temp;
    }
    construct();
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d %d",&l,&r);
        printf("%d %d\n", get_min(l - 1, r - 1, 1, 0, s - 1), get_max(l - 1, r - 1, 1, 0, s - 1));
    }
}