#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,y,z;
    cin>>n;
    vector<string> ans;
    while(n--){
        cin>>x>>y>>z;
        if(abs(x-z)<abs(y-z)) ans.push_back("Cat A");
        else if(abs(x-z)>abs(y-z)) ans.push_back("Cat B");
        else ans.push_back("Mouse C");
    }
    for(auto x:ans) cout<<x<<endl;
    return 0;
}
