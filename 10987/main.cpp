#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int cnt = 0;
    for(auto c : str) if(c=='a'|| c=='e'|| c=='i'|| c=='o'|| c=='u') cnt++;
    cout<<cnt;
}