#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    vector<int> a;
    int num;
    while(scanf("%d",&num)!=EOF){
        a.push_back(num);
    }
    int N=a.size();
    int L[N],L_id[N], T[N];
    int lis=0,lis_end=0;
    for(int i=0;i<N;i++){
        int pos=lower_bound(L,L+lis,a[i])-L;
        L[pos]=a[i];
        L_id[pos]=i;
        T[i]=(pos>0)?L_id[pos-1]:-1;
        if(pos+1>=lis){
            lis=pos+1;
            lis_end=i;
        }
    }
    printf("%d\n",lis);
    printf("-\n");
    stack<int> sol;
    int i=lis_end;
    while(lis--){
        sol.push(i);
        i=T[i];
    }
    while(!sol.empty()){
        printf("%d\n",a[sol.top()]);
        sol.pop();
    }
    return 0;
}