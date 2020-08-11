#include <iostream>

using namespace std;

int main()
{
    int n;
    int ans=0;
    cin>>n;
    for(int i = 0 ; i < n;i++){
        int temp;
        scanf("%d",&temp);
        ans+=temp;
    }
    cout<<ans-n+1;
}