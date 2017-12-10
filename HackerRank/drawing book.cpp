#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,p;
    cin>>n>>p;
    int res;
    res=min(p/2,(n-p)/2);
    cout<<res;

    return 0;
}
