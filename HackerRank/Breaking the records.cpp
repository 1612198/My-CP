#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> s(n);
    for(int i=0; i<n; i++)
        cin>>s[i];
    int best=s[0], bad=s[0];
    int nbest=0,nbad=0;
    for(int i=1;i<n;i++){
        if(s[i]>best) {
            best=s[i];
            nbest++;
        }
        else if(s[i]<bad){
            bad=s[i];
            nbad++;
        }
    }
    cout<<nbest<<" "<<nbad;

    return 0;
}
