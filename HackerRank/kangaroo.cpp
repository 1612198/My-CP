#include <bits/stdc++.h>
using namespace std;

bool isBoi(vector<int> a,int k){
    for(auto x:a){
        if(k%x!=0) return false;
    }
    return true;
}
bool isUoc(vector<int> b,int k){
    for(auto x:b){
        if(x%k!=0) return false;
    }
    return true;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int res=0;
    for(int k=a[n-1]; k<=b[m-1]; k++){
        if(isUoc(b,k)&& isBoi(a,k)) res++;
    }
    cout<<res;
    return 0;
}
