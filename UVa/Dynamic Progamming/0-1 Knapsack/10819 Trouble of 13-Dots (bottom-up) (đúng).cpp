#include <bits/stdc++.h>
using namespace std;

int m,n;
int p[105],f[105];
int c[10205]={0};

int maxi(int lower,int upper){
	int ans=c[lower];
	for(int i=lower+1;i<=upper;i++){
		ans=max(ans,c[i]);
	}
	return ans;
}

int main()
{
	// freopen("10819 in.txt","r",stdin);
	// freopen("10819 out.txt","w",stdout);
	while(scanf("%d%d",&m,&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d %d",p+i,f+i);
		memset(c,0,sizeof c);
		int U=m+200;
		for(int i=0;i<n;i++){
			for(int j=U;j>=p[i];j--){
				if(c[j-p[i]]!=0 || j==p[i]){
					c[j]=max(c[j],f[i]+c[j-p[i]]);//c[j] can receive another value before
				}
			}
		}	
		int ans=0;
		if(m<=1800) ans=maxi(0,m);
		if(m>1800 && m<=2000) ans=max(maxi(0,m),maxi(2001,m+200)); 
		if(m>2000) ans=maxi(0,m+200);
		printf("%d\n",ans);
	}


	return 0;
}