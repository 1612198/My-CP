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
    while(TC--){
        int n;
        scanf("%d",&n);
        if(n==0) {
            printf("0\n");
            continue;
        };
        int a[n];
        
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        reverse(a,a+n);
        int LIS[n];
        LIS[0]=1;
        //xet TH chuoi tang
        for(int i=1;i<n;i++){
            int maxj=0;
            for(int j=0;j<i;j++){
                if(LIS[j]>maxj && a[j]<a[i]) maxj=LIS[j];
            }
            LIS[i]=maxj+1;
        }
        int ans1=maxArr(LIS,n);
        cerr<<"ans1= "<<ans1<<endl;
        for(int i=0;i<n;i++)
            cerr<<LIS[i]<<" ";
        cerr<<endl;
        //xet TH chuoi giam
        int LDS[n]; //Long Decreasing Subsequence
        LDS[0]=1;
        for(int i=1;i<n;i++){
            int maxj=0;
            for(int j=0;j<i;j++){
                if(LDS[j]>maxj && a[j]>a[i]) maxj=LDS[j];
            }
            LDS[i]=maxj+1;
        }
        int ans2=maxArr(LDS,n);
        cerr<<"ans2= "<<ans2<<endl;
        for(int i=0;i<n;i++)
            cerr<<LDS[i]<<" ";
        cerr<<endl;
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(LIS[i]+LDS[i]-1>ans) {
                ans=LIS[i]+LDS[i]-1;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}