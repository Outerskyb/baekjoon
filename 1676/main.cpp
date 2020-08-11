#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int f=0;
    for(int i = 1;i<=n;i++){
        int c = i;
        while(c%5==0){
            c/=5;
            f++;
        }
    }
    cout<<f;
}

