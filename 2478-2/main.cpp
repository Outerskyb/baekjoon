#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    vector<int> vec;
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        vec.push_back(temp);
    }

    vector<int> vec2 = vec;
    for (int i = 1; i < N; i++){
        vec = vec2;
        rotate(vec.begin(), vec.begin() + i, vec.end());
        vector<int> temp_vec = vec;
        for (int j = 0; j < N-1; j++) {
            for (int k = j; k < N; k++) {
                vec = temp_vec;
                reverse(vec.begin() + j, vec.begin() + k);
                bool a = false;
                for (int l = 0; l < N-1; l++) {
                    if (vec[l] > vec[l + 1]) {
                        if (a == true) break;
                        a = true;
                    }
                }
                
            }
        }
    }

}