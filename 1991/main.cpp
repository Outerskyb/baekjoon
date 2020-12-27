#include <iostream>

using namespace std;

char lc[26];
char rc[26];

void pre(char curr) {
    cout << curr;
    if (lc[curr - 'A'] != 0) pre(lc[curr - 'A']);
    if (rc[curr - 'A'] != 0) pre(rc[curr - 'A']);
}
void in(char curr) {
    if (lc[curr - 'A'] != 0) in(lc[curr - 'A']);
    cout << curr;
    if (rc[curr - 'A'] != 0) in(rc[curr - 'A']);
}
void post(char curr) {
    if (lc[curr - 'A'] != 0) post(lc[curr - 'A']);
    if (rc[curr - 'A'] != 0) post(rc[curr - 'A']);
    cout << curr;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char node, l, r;
        cin >> node >> l >> r;
        if (l != '.')lc[node - 'A'] = l;
        if (r != '.')rc[node - 'A'] = r;
    }

    pre('A'); putchar('\n');
    in('A'); putchar('\n');
    post('A'); putchar('\n');

}