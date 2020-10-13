#include "bits/stdc++.h"

using namespace std;

int main()
{
    int a,b,c,d,e;
    cin >>a>>b>>c>>d>>e;
    cout<<std::min(c,std::min(a,b))+std::min(d,e)-50;
}