#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;


int main()
{
	// freopen("10306 in.txt","r",stdin);
	// freopen("10306 out.txt","w",stdout);

	int T;
	scanf("%d",&T);
	while(T--){
		int m,S;
		scanf("%d%d",&m,&S);
		pair<int,int> v[50];
		for(int i=0;i<m;i++)
			scanf("%d%d",&v[i].first,&v[i].second);
		
		int c[305][305]; 
		//c[i][j]: so coins de build i$(conventional) va j$ (infoTechnology)
		for(int i=0;i<=S;i++)
			for(int j=0;j<=S;j++) c[i][j]=INF;

		c[0][0]=0;
		for(int k=0;k<m;k++){
			for(int i=v[k].first;i<=S;i++){
				for(int j=v[k].second;j<=S;j++){
					c[i][j]=min(c[i][j],1+c[i-v[k].first][j-v[k].second]);
				}
			}
		}
		int ans=INF;
		for(int i=0;i<=S;i++)  //co trường hợp 1 bên = 0 hết mà
			for(int j=0;j<=S;j++)
				if(i*i+j*j==S*S) ans=min(ans,c[i][j]);
		if(ans>=INF) printf("not possible\n");
		else printf("%d\n",ans);

	}

	return 0;
}