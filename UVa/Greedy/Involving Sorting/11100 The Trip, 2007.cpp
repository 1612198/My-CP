#include <bits/stdc++.h>
using namespace std;

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	while(1){
		int b[n+1];
		for(int i=0;i<n;i++){
			scanf("%d",b+i);
		}
		sort(b,b+n);
		b[n]=-1; //linh canh
		int maxLug=1;
		int cur=1;
		for(int i=0;i<n;i++){
			if(b[i+1]==b[i]){
				cur++;
				continue;
			}
			else{
				if(cur>maxLug) maxLug=cur;
				cur=1;
			}
		}
		printf("%d\n",maxLug);
		for(int i=0;i<maxLug;i++){
			for(int j=i;j<n;j+=maxLug){   //+ 1 lượng maxLug sẽ ko bao giờ gặp b trùng
				printf("%d",b[j]);
				if(j+maxLug<n){ //chưa phải cuối :v
					printf(" ");
				} 
			}
			printf("\n");
		}
		scanf("%d",&n);
		if(n==0) break;
		else printf("\n");
	}	

	return 0;
}