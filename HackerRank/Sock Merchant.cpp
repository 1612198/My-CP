#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int c;
    int cnt[101]={0};
    for(int i=0;i<n;i++){
        cin>>c;
        cnt[c]++;
    }
    int res=0;
    for(int i=0;i<101; i++){
        res+=cnt[i]/2;
    }
    cout<<res;


    return 0;
}
