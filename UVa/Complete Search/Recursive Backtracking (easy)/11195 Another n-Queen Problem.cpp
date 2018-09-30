#include <bits/stdc++.h>
using namespace std;
int ans=0,n;
bitset<30> ld,rd,rw;  //initial full 0 all 30 elements

void backtrack(int c){
    if(c==n) {ans++; return; }
    for(int r=0;r<n;r++){
        if(board[r][c]!="*" && !rw[r] && !ld[r-c+n-1] && !rd[r+c]){
            rw[c]=ld[r-c+n-1]=rd[r+c]=true;
            backtrack(c+1);
            rw[c]=ld[r-c+n-1]=rd[r+c]=false;
        }
    }

}


int main()
{
    cin>>n;


    return 0;
}
