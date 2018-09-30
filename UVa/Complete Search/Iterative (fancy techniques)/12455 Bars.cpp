// generate all subset of set and evaluate sum all elements in subnet
// if sum == X -> okay else fail
#include  <bits/stdc++.h>
using namespace std;
int t;
int n,p;
int bar[25];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&p);
        for(int i=0;i<p;i++)
            scanf("%d",bar+i);
        int i=0;
        for( ;i<(1<<p);i++){
            int sum=0;
            for(int j=0;j<p;j++)
                if(i&(1<<j)) sum+=bar[j];
            if(sum==n){ printf("YES\n");break;}
        }
        if(i==(1<<p)) printf("NO\n");
    }


    return 0;
}
