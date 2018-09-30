#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n,r,d;
    while(scanf("%d%d%d",&n,&d,&r),n||d||r){
        vector<int> mor(n),eve(n);
        for(int i=0;i<n;i++){
            scanf("%d",&mor[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&eve[i]);
        }
        sort(mor.begin(),mor.end());
        sort(eve.rbegin(),eve.rend());
        int over=0;
        for(int i=0;i<n;i++){
            over+=max(0,mor[i]+eve[i]-d);
        }
        printf("%d\n",over*r);
    }

    return 0;
}