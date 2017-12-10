#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<char> s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int pos=0,res=0;
    for(int i=0;i<n;i++){
        if(s[i]=='U') pos++;
        else pos--;
        if(pos<0){
            i++;
            while(i<n){
                if(s[i]=='U')pos++;
                else pos--;
                if(pos==0){
                    res++;
                    break;
                }
                i++;
            }
        }
    }
    cout << res;
    return 0;
}
