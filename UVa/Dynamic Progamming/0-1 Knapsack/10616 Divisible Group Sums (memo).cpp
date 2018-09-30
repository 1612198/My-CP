#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N,Q,D,M;
ll a[250];
ll memo[205][21][11];  //id<=200, sum<=20 (sum%=D) M<=10
ll count(int id,int sum,int m){  //m: so phan tu cua tap con
	if(m==M) return sum==0;
	if(id>=N) return 0; //no items
	ll &ans=memo[id][sum][m];
	if(ans!=-1) return ans;
	ll ans1=0,ans2=0;
	ll s=(sum+a[id])%D;  //s=((sum+a[i])%D+D)%D;
	if(s<0) s+=D;  //dư ra âm thì bù vào cho dương vì chỉ số sum>=0
	ans1=count(id+1,sum,m);
	ans2=count(id+1,s,m+1);
	ans=ans1+ans2;
	return ans;

}


int main()
{
	freopen("10616 in.txt","r",stdin);
	freopen("10616 out.txt","w",stdout);
	int set=1;
	while(scanf("%d%d",&N,&Q),N||Q){
		for(int i=0;i<N;i++)
			scanf("%lld",a+i);
		// for(int i=0;i<N;i++)
		// 	cerr<<a[i]<<" ";
		// cerr<<endl;

		printf("SET %d:\n",set++);
		for(int q=1;q<=Q;q++){
			scanf("%d%d",&D,&M);
			memset(memo,-1,sizeof memo);
			// cerr<<"D="<<D<<" M="<<M<<endl;
			ll ans=count(0,0,0);
			printf("QUERY %d: %lld\n",q,ans);
		}
	}


	return 0;
}