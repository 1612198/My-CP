#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;
const int maxP=2e4+4;

int T, price, n;   //price<=1e4, n<=1e2
int d[105]; //denomination
int main()
{
	freopen("11517 in.txt","r",stdin);
	freopen("11517 out.txt","w",stdout);
	scanf("%d",&T);

	while(T--){
		scanf("%d %d",&price,&n);
		for(int i=1;i<=n;i++){
			scanf("%d",d+i);
		}
		vector<vector<int>> c(105,vector<int>(20004)); //nhớ chỗ sài vector  2d này nhé
		//c[i][j]: so coins min to build j$
		for(int i=0;i<=n;i++)
			for(int j=1;j<maxP;j++) c[i][j]=INF;
		for(int i=0;i<=n;i++) c[i][0]=0;

		for(int i=1;i<=n;i++){
			for(int j=1;j<maxP;j++){
				if (j-d[i]>=0)
					c[i][j]=min(c[i-1][j],1+c[i-1][j-d[i]]);
				else c[i][j]=c[i-1][j];
			}
		}
		// for(int i=0;i<=10;i++){
		// 	for(int j=0;j<=10;j++)
		// 		if(c[i][j]==INF) cerr<<"IF ";
		// 		else cerr<<c[i][j]<<"  ";
		// 	cerr<<endl;
		// }
		int ans;
		for(ans=price;c[n][ans]>=INF;ans++);
		printf("%d %d\n",ans,c[n][ans]);

	}

	return 0;
}