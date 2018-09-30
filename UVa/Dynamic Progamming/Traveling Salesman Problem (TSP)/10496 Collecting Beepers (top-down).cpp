#include <bits/stdc++.h>
using namespace std;

int TC,xsize,ysize,n,x[11],y[11],dist[11][11],memo[11][1<<11];

int tsp(int pos,int bitmask){  //pos: current position, bitmask: bit=1: đã qa, bit=0 chưa qua
	if(bitmask==(1<<(1+n))-1)
		return dist[pos][0];
	if(memo[pos][bitmask]!=-1) 
		return memo[pos][bitmask];
	int ans=2*1e9;
	for(int nxt=1;nxt<=n;nxt++){
		if(nxt!=pos && !(bitmask&(1<<nxt)))
			ans=min(ans,dist[pos][nxt]+tsp(nxt,bitmask|(1<<nxt)));
	}
	return memo[pos][bitmask]=ans;


}

int main()
{
	freopen("10496 in.txt","r",stdin);
	// freopen("10496 out.txt","w",stdout);
	scanf("%d",&TC);
	while(TC--){
		scanf("%d%d",&xsize,&ysize);
		scanf("%d%d",&x[0],&y[0]);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&x[i],&y[i]);

		//build distance table
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				dist[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);

		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++)
				cerr<<dist[i][j]<<" ";		
			cerr<<endl;
		}
		memset(memo,-1,sizeof memo);
		printf("The shortest path has length %d\n",tsp(0,1));
		// for(int i=0;i<11;i++){
		// 	for(int j=0;j<40;j++)
		// 		cout<<memo[i][j]<<" ";
		// 	cout<<endl;
		// }

	}

	return 0;
}