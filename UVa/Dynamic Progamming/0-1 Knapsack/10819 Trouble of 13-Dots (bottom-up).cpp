#include <bits/stdc++.h>
using namespace std;

int m,n;
int p[105],f[105];
int ff[105][11005];// chọn trong n đồ đạc và cái cuối là n (1..n)
int w[105][10205];
void solve(){
	memset(ff,0,sizeof ff);
	memset(w,0,sizeof w);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m+200;j++){
			if(j<p[i]) ff[i][j]=ff[i-1][j];
			else ff[i][j]=max(ff[i-1][j],f[i]+ff[i-1][j-p[i]]);
		}
	}
}

//truy vet tinh sum
int traceSum(int j){
	int i=n; //1.2 vs 1 cho day ne
	int sum=0;
	while(i){
		if(ff[i][j]==ff[i-1][j]){//ko lay
			sum+=0;
		}
		else {
			sum+=p[i];
			j=j-p[i];
			// cerr<<"pi="<<p[i]<<endl;
			// cerr<<"sum="<<sum<<endl;
		}
		i--;
	}
	return sum;
}

int main()
{
	freopen("10819 in.txt","r",stdin);
	freopen("10819 out.txt","w",stdout);
	while(scanf("%d%d",&m,&n)!=EOF){
		for(int i=1;i<=n;i++)
			scanf("%d %d",p+i,f+i);
		solve();
		for(int i=0;i<=n;i++){
			for(int j=0;j<=200+m;j++)
				cout<<ff[i][j]<<" ";
			cout<<endl;
		}
		int ans=ff[n][m];
		// cerr<<"m="<<ff[n][m]<<endl;
		// cerr<<"m+200="<<ff[n][m+200]<<endl;
		// int mm=200+m;
		// int sum=traceSum();
		// cerr<<"sum="<<sum<<endl;
		// if(sum>2000 && (200+m)>=sum) {
		// 	cerr<<"loi gi day\n";
		// 	printf("%d\n",ff[n][mm]);
		// }
		// else printf("%d\n",ff[n][m]);
		// printf("%d\n",ans);

		//ta tim max trong m+1->m+200 va thoa dk sum > 2000
		// int ans=0;
		for(int j=m+1;j<=m+200;j++){
			cerr<<"traceSum="<<traceSum(j)<<endl;
			if(ff[n][j]>ans && traceSum(j)>2000)
				ans=ff[n][j];
		}
		printf("%d\n",ans);
	}


	return 0;
}