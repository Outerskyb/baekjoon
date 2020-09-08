#include <iostream>
#include <vector>

using namespace std;

vector<int> fibo;

void make_fibo()
{
int prev = 0;
	int curr = 1;
	int now = 1;
    fibo.push_back(now);
	for (int i = 0; now<100001; i++) {
		now = curr + prev;
		prev = curr;
		curr = now;
        fibo.push_back(now);
	}	
}

int main()
{
	int d,k;
	cin >> d;
    cin >> k;
	make_fibo();
    
    for(int i = 1; i <= 50000;i++){
        for(int j = 1; j <= 50000;j++){
            if(fibo[d-3]*i+fibo[d-2]*j  == k){
                cout<<i<<'\n'<<j;
                return 0;
            }
        }
    }
    
}