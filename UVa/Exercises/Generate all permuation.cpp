//Đề: nhập vào 1 set n a1,a2,..,an
//In ra tất cả các hoán vị của a
#include <bits/stdc++.h>
using namespace std;
int n;
int a[100];
int ans[100];
bool place(int pos,int x){
    for(int i=0;i<pos;i++)
        if(ans[i]==x) return false;
    return true;
}

void backtrack(int pos){ //position of index i in array a
    if(pos==n){
        for(int i=0;i<n;i++)
            printf("%d  ",ans[i]);
        printf("\n");
    }
    else{
        for(int i=0;i<n;i++){
            if(place(pos,a[i])){
                ans[pos]=a[i];
                backtrack(pos+1);
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    //memset(ans,0,sizeof(ans));
    for(int i=0;i<n;i++)
        scanf("%d",a+i); //if you want to print  lexicographically, sort a before backtrack
    //sort(a,a+n);
    backtrack(0);


    return 0;
}
