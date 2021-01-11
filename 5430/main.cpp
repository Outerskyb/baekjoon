#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <deque>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string p;
        cin >> p;
        int n;
        cin >> n;
        char temp;
        cin >> temp;
        string a;
        cin >> a;
        a.pop_back();
        deque<int> d;
        auto vec = split(a, ',');
        for (auto el : vec) d.push_back(stoi(el));
        

        bool front = true;
        for (const auto& f : p) {
            if (f == 'R') {
                front = !front;
            }
            else if(d.size()==0){
                cout << "error\n";
                goto out;
            }
            else if(front) {
                d.pop_front();
            }
            else if (!front) {
                d.pop_back();
            }
        }
        if (d.size() == 0) {
            cout << "[]\n";
        }
        else if (front) {
            cout << "[";
            for (auto it = d.begin(); it != --d.end(); ++it) {
                cout << *it << ',';
            }
            cout << d.back()<< "]\n";
        }
        else {
            cout << "[";
            for (auto it = d.rbegin(); it != --d.rend(); ++it) {
                cout << *it << ',';
            }
            cout << d.front() << "]\n";
        }
    out:;
    }
}