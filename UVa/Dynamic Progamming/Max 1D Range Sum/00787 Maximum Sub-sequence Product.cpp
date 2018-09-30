//phiên bản C++ áp dụng cho mấy số nhỏ nhỏ thôi nhé
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int a[105];
	int tmp;
	int i=0;
	while(scanf("%d",&tmp)!=EOF){
		if(tmp!=-999999) a[i++]=tmp;
		else {
			int n=i;
			i=0;
			long long ans=-1e18;
			for(int i=0;i<n;i++){
				long long prod=1;
				for(int j=i;j<n;j++){
					prod*=a[j];
					ans=max(ans,prod);
				}			
			}
			printf("%lld\n",ans);
		}
	}

	return 0;
}