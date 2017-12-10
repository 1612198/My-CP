#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s,n,m;
    cin>>s>>n>>m;
    vector<int> k(n);
    vector<int> u(m);
    for(int i=0;i<n;i++) cin>>k[i];
    for(int i=0;i<m;i++) cin>>u[i];
    int mmax=-1;
    int sum=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            sum=k[i]+u[j];
            if(sum<=s) mmax=max(mmax,sum);
        }
    }

    cout<<mmax;
    return 0;
}
