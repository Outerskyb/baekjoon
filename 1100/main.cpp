#include <iostream>
#include <string>

using namespace std;

int main()
{
    string strs[8];
    int count = 0;
    for(int i = 0 ; i < 8 ; ){
        cin>>strs[i++];
    }
    for(int i = 0 ; i < 8;i++){
        for(int j = 0 ; j < 8; j++){
            if((i+j)%2 == 0 && strs[i][j] =='F') count++;
        }
    }
    cout << count;
}