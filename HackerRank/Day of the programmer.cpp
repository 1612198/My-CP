#include <bits/stdc++.h>
using namespace std;
int main()
{
    int y;
    cin>>y;
    if(y<=1917){
        if(y%4==0) cout<<"12.09.";
        else cout<<"13.09.";
    }
    else if(y>=1919){
            if((y%4==0 && y%100!=0)||(y%400==0)) cout<<"12.09.";
            else cout<<"13.09.";
         }
         else{
            cout<<"25.09.";
         }
    cout<<y;
    return 0;
}
