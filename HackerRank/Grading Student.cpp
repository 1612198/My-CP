#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> gr(n);
    for(int i=0; i<n; i++)
        cin>>gr[i];
    vector<int> ss(15); //vector to compare with gr
    int x=40;
    for(int i=0;i<15;i++){
        ss[i]=x;
        x+=5;
    }
    for(int i=0;i<n;i++){
        int j=0;
        while(gr[i]>ss[j]) j++;
        if(ss[j]-gr[i] <3) gr[i]=ss[j];
    }
    for(auto x: gr)
        cout<<x<<endl;

    return 0;
}
