#include <bits/stdc++.h>
using namespace std;
int k;
int a[14];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&k);
    while(k){
        for(int i=0;i<k;i++)
            scanf("%d",a+i);
        for(int i=0;i<k-5;i++)
            for(int j=i+1;j<k-4;j++)
                for(int l=j+1;l<k-3;l++)
                    for(int m=l+1;m<k-2;m++)
                        for(int n=m+1;n<k-1;n++)
                            for(int o=n+1;o<k;o++)
                                printf("%d %d %d %d %d %d\n",a[i],a[j],a[l],a[m],a[n],a[o]);
        scanf("%d",&k);
        if(k) printf("\n");
    }

    return 0;
}
