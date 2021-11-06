#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int GO_MAX = 10;

class Trie
{
public:
    Trie* go[GO_MAX];
    bool output;
    bool goexist;

    Trie() {
        fill(go, go + GO_MAX, nullptr);
        output = goexist = false;
    }

    ~Trie() {
        for (int i = 0; i < GO_MAX; i++)
            if (go[i]) delete go[i];
    }

    void insert(const char* key) {
        if (*key == '\0') output = true;
        else {
            int next = *key - '0';
            if (!go[next]) go[next] = new Trie;
            goexist = true;
            go[next]->insert(key + 1);
        }
    }

    bool consistent(){
        if (goexist && output) return false;
        for (int i = 0; i < GO_MAX; i++)
            if (go[i] && !go[i]->consistent()) return false;
        return true;
    }
    
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        Trie* root = new Trie; 
        for (int i = 0; i < N; i++) {
            char tel[11];
            cin >> tel;
            root->insert(tel);
        }
        puts(root->consistent() ? "YES" : "NO");
        delete root;
    }
}

