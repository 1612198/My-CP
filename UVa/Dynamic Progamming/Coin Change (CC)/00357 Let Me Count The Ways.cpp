#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	freopen("00357 in.txt","r",stdin);
	freopen("00357 out.txt","w",stdout);
	int n; //
	int set[]={0,1,5,10,25,50};
	while(scanf("%d",&n)!=EOF){
		ll c[10][30005]={0};
		for(int i=0;i<=6;i++)
		c[i][0]=1; //base case 
	
		for(int i=1;i<=6;i++){
			for(int j=1;j<=n;j++){
				if(j-set[i]>=0) c[i][j]+=c[i][j-set[i]];
				c[i][j]+=c[i-1][j];
			}
		}
		if(c[6][n]>=2)
			printf("There are %lld ways to produce %d cents change.\n",c[6][n],n);
		else 
			printf("There is only 1 way to produce %d cents change.\n",n);

	}


	return 0;
}