#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int L;
std::vector<std::vector<int>> lines;

bool check(std::vector<int> line) {
    bool isDescending = false;
    int widthCount = 1;
    int prev = line.front();
    for (int i = 1; i < N; i++) {
        int curr = line[i];
        if (prev - curr > 1 || prev - curr < -1)
            return false;
        if (prev == curr) {
            widthCount++;
            if (isDescending == 1) {
                if (widthCount >= L) {
                    isDescending = false;
                    widthCount = 0;
                }
            }
        }
        else if (prev > curr) {
            if (isDescending) {
                return false;
            }
            else if (L == 1) {
                widthCount = 0;
            }
            else {
                isDescending = true;
                widthCount = 1;
            }
            
        }
        else if (prev < curr) {
            if (isDescending) {
                return false;
            }
            else if(widthCount < L){
                return false;
            }
            widthCount = 1;
        }
        prev = curr;
    }   
    if (isDescending) {
        return false;
    }
    return true;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> L;

    for (int i = 0; i < N*2; i++) 
        lines.push_back(std::vector<int>());
   
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            lines[i].push_back(temp);
            lines[N + j].push_back(temp);
        }
    }

    int ans = 0;
    for (const auto& line : lines) {
        ans += check(line);
    }
    cout << ans;

    return 0;
}