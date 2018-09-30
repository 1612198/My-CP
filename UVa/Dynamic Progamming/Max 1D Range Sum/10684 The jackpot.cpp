#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	while(scanf("%d",&n),n){
		int a[n];
		for(int i=0;i<n;i++)
			scanf("%d",a+i);  //0<a[i]<1000 => ans!=0
		int Sum=0, ans=0;
		for(int i=0;i<n;i++){
			Sum+=a[i];
			ans=max(ans,Sum);
			if(Sum<0) Sum=0;
		}
		if(ans==0){
			printf("Losing streak.\n");
		}
		else{
			printf("The maximum winning streak is %d.\n",ans);
		}
	}

	return 0;
}