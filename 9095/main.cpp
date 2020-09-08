#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    int mybmi[11] = {1,2,4};
    for(int i = 3 ; i<12;i++){
        mybmi[i] = mybmi[i-1]+mybmi[i-2]+mybmi[i-3];
    }
    while(T--){
        int n;
        cin>>n;
        cout<<mybmi[n-1]<<'\n';
    }
}