//NX: sai ý tưởng, tiền lớn hơn chưa chắc đã đổi được nhìu loại coin hơn

#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int c[n];
		for(int i=0;i<n;i++){
			scanf("%d",c+i);
		}
		int k=0;
		int sum=0;
		for(int i=0;i<n;i++){
			if(sum<c[i]){
				//chon c[i]
				k++;
				sum+=c[i];
			}else{
				//chon c[i] & bo chon c[i-1]
				sum-=c[i-1];
				sum+=c[i];
			}
		}
		printf("%d\n",k);
		
	}

	return 0;
}