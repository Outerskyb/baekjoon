#include "bits/stdc++.h"

using namespace std;

int board[10][10];
int n,m;
int bx,by;
int rx,ry;

struct  s
{
    int board[10][10];
    int bx;
    int by;
    int rx;
    int ry;
    int l;
};


bool tilt(int(*board)[10],int way){
    if(way == 0){
        if(rx<bx){
            for(int i = 0 ; i < 10 ; i++){
                if(rx>0){
                    if(board[ry][rx-1] == 2)
                        return true;
                    else if(board[ry][rx-1]==1)
                        break;
                    else board[ry][rx] = 0,board[ry][--rx] = 3;
                }else break;
            }
            for(int i = 0 ; i < 10 ; i++){
                if(bx>0){
                    if(board[by][bx-1] == 2)
                        return true;
                    else if(board[by][bx-1]==1||board[by][bx-1]==3)
                        break;
                    else board[by][bx] = 0,board[by][--bx] = 4;
                }else break;
            }
        }else{
            for(int i = 0 ; i < 10 ; i++){
                if(bx>0){
                    if(board[by][bx-1] == 2)
                        return true;
                    else if(board[by][bx-1]==1)
                        break;
                    else board[by][bx] = 0,board[by][--bx] = 4;
                }else break;
            }
            for(int i = 0 ; i < 10 ; i++){
                if(rx>0){
                    if(board[ry][rx-1] == 2)
                        return true;
                    else if(board[ry][rx-1]==1||board[ry][rx-1] == 4)
                        break;
                    else board[ry][rx] = 0,board[ry][--rx] = 3;
                }else break;
            }
        }
    }
    else if(way==1){
        if(ry>by){
            for(int i = 0 ; i < 10 ; i++){
                if(ry<n-1){
                    if(board[ry+1][rx] == 2)
                        return true;
                    else if(board[ry+1][rx]==1)
                        break;
                    else board[ry][rx] = 0,board[++ry][rx] = 3;
                }else break;
            }
            for(int i = 0 ; i < 10 ; i++){
                if(by<n-1){
                    if(board[by+1][bx] == 2)
                        return true;
                    else if(board[by+1][bx]==1||board[by+1][bx]==3)
                        break;
                    else board[by][bx] = 0,board[++by][bx] = 4;
                }else break;
            }
        }else{
            for(int i = 0 ; i < 10 ; i++){
                if(by<n-1){
                    if(board[by+1][bx] == 2)
                        return true;
                    else if(board[by+1][bx]==1)
                        break;
                    else board[by][bx] = 0,board[++by][bx] = 4;
                }else break;
            }
            for(int i = 0 ; i < 10 ; i++){
                if(ry< n-1){
                    if(board[ry+1][rx] == 2)
                        return true;
                    else if(board[ry+1][rx]==1||board[ry+1][rx] == 4)
                        break;
                    else board[ry][rx] = 0,board[++ry][rx] = 3;
                }else break;
            }
        }
    }

    else if(way==2){
        if(rx>bx){
            for(int i = 0 ; i < 10 ; i++){
                if(rx<n-1){
                    if(board[ry][rx+1] == 2)
                        return true;
                    else if(board[ry][rx+1]==1)
                        break;
                    else board[ry][rx] = 0,board[ry][++rx] = 3;
                }else break;
            }
            for(int i = 0 ; i < 10 ; i++){
                if(bx<n-1){
                    if(board[by][bx+1] == 2)
                        return true;
                    else if(board[by][bx+1]==1||board[by][bx+1]==3)
                        break;
                    else board[by][bx] = 0,board[by][++bx] = 4;
                }else break;
            }
        }else{
            for(int i = 0 ; i < 10 ; i++){
                if(bx<n-1){
                    if(board[by][bx+1] == 2)
                        return true;
                    else if(board[by][bx+1]==1)
                        break;
                    else board[by][bx] = 0,board[by][++bx] = 4;
                }else break;
            }
            for(int i = 0 ; i < 10 ; i++){
                if(rx< n-1){
                    if(board[ry][rx+1] == 2)
                        return true;
                    else if(board[ry][rx+1]==1||board[ry][rx+1] == 4)
                        break;
                    else board[ry][rx] = 0,board[ry][++rx] = 3;
                }else break;
            }
        }
    }

    else if(way==3){
        if(ry<by){
            for(int i = 0 ; i < 10 ; i++){
                if(ry>0){
                    if(board[ry-1][rx] == 2)
                        return true;
                    else if(board[ry-1][rx]==1)
                        break;
                    else board[ry][rx] = 0,board[--ry][rx] = 3;
                }else break;
            }
            for(int i = 0 ; i < 10 ; i++){
                if(by>0){
                    if(board[by-1][bx] == 2)
                        return true;
                    else if(board[by-1][bx]==1||board[by-1][bx]==3)
                        break;
                    else board[by][bx] = 0,board[--by][bx] = 4;
                }else break;
            }
        }else{
            for(int i = 0 ; i < 10 ; i++){
                if(by>0){
                    if(board[by-1][bx] == 2)
                        return true;
                    else if(board[by-1][bx]==1)
                        break;
                    else board[by][bx] = 0,board[--by][bx] = 4;
                }else break;
            }
            for(int i = 0 ; i < 10 ; i++){
                if(ry > 0){
                    if(board[ry-1][rx] == 2)
                        return true;
                    else if(board[ry-1][rx]==1||board[ry-1][rx] == 4)
                        break;
                    else board[ry][rx] = 0,board[ry-1][rx] = 3;
                }else break;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j <m;j++){
            char temp;
            cin >> temp;
            board[i][j] = temp=='.'?0:temp=='#'?1:temp=='O'?2:temp=='R'?3:4;
            if(temp == 3) rx = i, ry = j;
            if(temp == 4) bx = i, by = j;
        }
    }
    queue<s> q;
    

}