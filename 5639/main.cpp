#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int bst[1007090];
    memset(bst,-1,sizeof bst);
    int num;
    int pointer = 1;
    cin >> num;
    bst[pointer] = num;
    while(cin >> num){
        if(num<bst[pointer]){
            bst[pointer = pointer*2] = num;
        }else {
            while(bst[pointer+1]==-1&&bst[pointer/2]<num) pointer/=2;
            bst[pointer = pointer*2+1] = num;
        }
    }
    pointer = 1;
    while(pointer){
        if(bst[pointer*2]>0){
            pointer*=2;
        }else if(bst[pointer*2+1]>0){
            pointer=pointer*2+1;
        }else{
            cout << bst[pointer]<<'\n';
            bst[pointer]=-1;
            pointer/=2;
        }
    }
}