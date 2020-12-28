#include <iostream>
#include <string>

using namespace std;

struct Node {
    int v;
    Node* p;
    Node* n;
};

class Deque {
public:
    Deque() {
        fs = new Node;
        bs = fs;
        fs->p =  bs->n = nullptr;
        fs->n = bs;
        bs->p = fs;
    }
    Node* fs, *bs;
    int s = 0;
    void push_back(int x) {
        Node* a = new Node;
        a->v=x,a->p=bs,a->n=bs->n;
        bs->n = a;
        bs = a;
        if (s == 0) fs = bs;
        s++;
    }
    void push_front(int x) {
        Node* a = new Node;
        a->v = x, a->p = fs->p, a->n = fs;
        fs->p = a;
        fs = a;
        if (s == 0) bs=fs;
        s++;
    }
    void pop_back() {
        if(s == 0)  cout << "-1\n";
        else if (bs != nullptr) {
            cout << bs->v << '\n';
            bs = bs->p;
            s--;
        }
        
    }
    void pop_front() {
        if (s == 0)  cout << "-1\n";
        else if (fs != nullptr) {
            cout << fs->v << '\n';
            fs = fs->n;
            s--;
        }
    }
    void size() {
        cout << s << '\n';
    }
    void empty() {
        cout << (s == 0) << '\n';
    }
    void front() {
        if (s == 0)  cout << "-1\n";
        else if (fs != nullptr) {
            cout << fs->v << '\n';
        }
    }
    void back() {
        if (s == 0)  cout << "-1\n";
        else if (bs != nullptr) {
            cout << bs->v << '\n';
        }
    }
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    Deque d;
    int num;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (str == "push_back") {
            cin >> num;
            d.push_back(num);
        }
        else if (str == "push_front") {
            cin >> num;
            d.push_front(num);
        }
        else if (str == "pop_back") {
            d.pop_back();
        }
        else if (str == "pop_front") {
            d.pop_front();
        }
        else if (str == "size") {
            d.size();
        }
        else if (str == "empty") {
            d.empty();
        }
        else if (str == "front") {
            d.front();
        }
        else if (str == "back") {
            d.back();
        }
    }

}