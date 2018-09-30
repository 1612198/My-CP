#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[250];
int N,Q,D,M;

ll dp[205][15][25];//dp[i][j][k]: trong i phần tử lấy j thằng sao cho tổng chia D dư k

void solve(){
	memset(dp,0,sizeof dp);
	dp[0][0][0]=1;// lấy 0 phần tử từ set 0 phần tử cho tổng chia k dư 0, thì đúng rồi, ví dụ khi dp[1][1][0]=dp[0][0][0]+dp[0][1][0] 
					//vd la D=2, va a[i]=4, thi ((k-a[i]%D)%D+D)%D => ((k-a[i])%D)+D)%D thì đáp án phải là 1 chính là do dp[0][0][0] build lên
	// for(int i=0;i<=N;i++){
	// 	for(int j=0;j<=M;j++){
	// 		for(int k=0;k<D;k++)
	// 			cout<<dp[i][j][k]<<"  ";
	// 		cout<<endl;
	// 	}
	// 	cout<<endl;
	// }
	for(int i=1;i<=N;i++){//i: số phần tử nên phải tới N, i=5 thì các phần tử từ a0->a4
		for(int j=0;j<=M;j++){//j phải từ 0 vì dp[i][0][0]=1; tap rong a
			for(int k=0;k<D;k++){
				ll tmp = (k+a[i])%D;
				if(tmp < 0) tmp += D;
				dp[i][j][k]=dp[i-1][j][k]; //chủ yếu kéo thg j=0
				if(j>0) dp[i][j][k]+=dp[i-1][j-1][tmp];
			}
		}
	}
	for(int i=0;i<=N;i++){
		for(int j=0;j<=M;j++){
			for(int k=0;k<D;k++)
				cout<<dp[i][j][k]<<"  ";
			cout<<endl;
		}
		cout<<endl;
	}
}


int main()
{
	freopen("10616 in.txt","r",stdin);
	freopen("10616 out.txt","w",stdout);

	int set=1;
	while(scanf("%d%d",&N,&Q),N||Q){
		for(int i=1;i<=N;i++)  //luon đọc từ 1 để hàng 0 làm base, vì khi lấy hàng 1 và ko lấy hang 1 thì cần hàng 0 đẻ build lên 1
			scanf("%lld",a+i);
		cout<<"input\n";
		for(int i=1;i<=N;i++)
			cout<<a[i]<<" ";
		cout<<endl;

		printf("SET %d:\n",set++);
		for(int q=1;q<=Q;q++){
			scanf("%d%d",&D,&M);
			solve();
			ll ans=dp[N][M][0];
			printf("QUERY %d: %lld\n",q,ans);
		}
	}


	return 0;
}