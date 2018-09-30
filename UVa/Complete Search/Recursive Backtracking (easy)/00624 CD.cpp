#include <bits/stdc++.h>
using namespace std;

int N,n,t[30];


int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	while(scanf("%d %d",&N,&n)!=EOF){
		int sum=0,Max=0,best;
		for(int i=0;i<n;i++){
			scanf("%d",&t[i]);
		}
		for(int i=0;i<(1<<n); i++){
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					sum+=t[j];
				}
			}
			if(sum>Max && sum<=N){
				Max=sum;
				best=i;
			}
			sum=0;
		}
		for(int j=0;j<n;j++){
			if(best&(1<<j)) {
				printf("%d ",t[j]);
			}
		}
		printf("sum:%d\n",Max);
	}
	return 0;
}