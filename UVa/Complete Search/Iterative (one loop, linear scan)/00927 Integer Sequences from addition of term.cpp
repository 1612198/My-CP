#include <bits/stdc++.h>
using namespace std;

int c;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&c);
	while(c--){
		int deg;
		scanf("%d",&deg);
		vector<int> c(deg+1);
		for(int i=0;i<=deg;i++)
			scanf("%d",&c[i]);
		int d,k;
		scanf("%d%d",&d,&k);
		int x=1, index=0;
		for( x=1;;x++){
			index+=d*x;
			if(index>=k) break;
		}
		long long a_x=0;
		for(int i=0;i<=deg;i++){
			a_x+=c[i]*pow(x,i);
		}
		printf("%lld\n",a_x);
	}


	return 0;
}
