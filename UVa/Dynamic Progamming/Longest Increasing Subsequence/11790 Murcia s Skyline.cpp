#include <bits/stdc++.h>
using namespace std;

int maxArr(int a[],int n){
    int max=a[0];
    for(int i=1;i<n;i++)
        if(a[i]>max) max=a[i];
    return max;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int TC;
    scanf("%d",&TC);
    for(int c=1;c<=TC;c++){
        int n;
        scanf("%d",&n);
        int a[n],length[n];
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        for(int i=0;i<n;i++)
            scanf("%d",length+i);

        int LIS[n];
        LIS[0]=length[0];
        for(int i=1;i<n;i++){
            int maxj=0; 
            for(int j=0;j<i;j++)
                if(LIS[j]>maxj && a[j]<a[i]) maxj=LIS[j];
            LIS[i]=maxj+length[i];
        }

        int LIS_max=maxArr(LIS,n);
        int LDS[n];
        LDS[0]=length[0];
        for(int i=1;i<n;i++){
            int maxj=0; 
            for(int j=0;j<i;j++)
                if(LDS[j]>maxj && a[j]>a[i]) maxj=LDS[j];
            LDS[i]=maxj+length[i];
        }

        int LDS_max=maxArr(LDS,n);
        if(LIS_max>=LDS_max) {
            printf("Case %d. Increasing (%d). Decreasing (%d).\n",c,LIS_max,LDS_max);
        }else printf("Case %d. Decreasing (%d). Increasing (%d).\n",c,LDS_max,LIS_max);
    }

    return 0;
}