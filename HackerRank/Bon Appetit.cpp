#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> c(n);
    int sum=0;
    for(int i=0; i<n; i++){
        cin>>c[i];
        sum+=c[i];
    }
    int b;
    cin>>b;
    if(b==(sum-c[k])/2) cout<<"Bon Appetit";
    else{
        cout<<b-(sum-c[k])/2;
    }

    return 0;
}
