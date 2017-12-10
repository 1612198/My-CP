#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s,t,a,b,m,n;
    cin>>s>>t>>a>>b>>m>>n;
    vector<int> app(m);
    vector<int> ora(n);
    for(int i=0; i<m; i++)
        cin>>app[i];
    for(int i=0; i<n; i++)
        cin>>ora[i];

    int na=0,no=0;
    for(auto x:app){
        if(x+a>=s && x+a<=t) na++;
    }
    for(auto x:ora)
        if(x+b>=s && x+b<=t) no++;
    cout<<na<<endl<<no<<endl;


    return 0;
}
