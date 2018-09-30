#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
	if(b.second-b.first==a.second-a.first) return (a.first<b.first);
	return (a.second-a.first) > (b.second-b.first); //đứng trưóc phải lớn hơn đứng sau, sai thì phải swap
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int TC;
	scanf("%d",&TC);
	cerr<<TC<<endl;
	for(int c=1;c<=TC;c++){
		int n;
		scanf("%d",&n);
		cerr<<n<<endl;
		int a[n+5]={0};
		for(int i=2;i<=n;i++){// a[i] is between stop i-1 to stop i
			scanf("%d",a+i);
		}
		for(int i=2;i<=n;i++){
			cerr<<a[i]<<" ";
		}
		cerr<<endl;
		int dp[n+1];//range sum max end at i (contain a[i])
		dp[1]=0;
		int sum=0;
		for(int i=2;i<=n;i++){
			sum+=a[i];
			dp[i]=sum;
			if(sum<0) sum=0;
		}
		for(int i=2;i<=n;i++)
			cerr<<dp[i]<<" ";
		cerr<<endl;
		for(int i=2;i<=n;i++){
			if(dp[i]>=dp[1]) {
				dp[1]=dp[i]; //dp[1] max range sum
			}
		}
		cerr<<dp[1]<<endl;
		for(int i=3;i<=n;i++){
			a[i]+=a[i-1];
		}
		for(int i=2;i<=n;i++){
			cerr<<a[i]<< " ";
		}
		cerr<<endl;
		vector<pair<int,int>> range;
		for(int i=2;i<=n;i++){
			if(dp[i]==dp[1]) range.push_back(make_pair(0,i));
		}
		for(int i=0;i<range.size();i++){
			cerr<<"end= "<<range[i].second<<endl;
		}
		for(int i=0;i<range.size();i++){
			int x=a[range[i].second] - dp[1];
			cerr<<"x="<<x<<endl;
			int* it=find(a+1,a+n+1,x);  //find thì linear
			cerr<<"*it = "<<*it<<endl;
			int first=it-a;
			cerr<<"first = "<<first<<endl;
			range[i].first=first;
		}
		cerr<<"size range="<<range.size()<<endl;
		for(int i=0;i<range.size();i++){
			cerr<<"first= "<<range[i].first<<"  end= "<<range[i].second<<endl;
		}
		int j;
		
		if(range.size()==0) printf("Route %d has no nice parts\n",c); //dp[1]==0
		else{
			sort(range.begin(),range.end(),cmp);
			
			for(int i=0;i<range.size();i++){
				cerr<<"first = "<<range[i].first<<" second= "<<range[i].second<<endl;
			}
			printf("The nicest part of route %d is between stops %d and %d\n",c,range[0].first,range[0].second);
		}
	}
	return 0;

}