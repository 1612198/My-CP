#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int c=1;c<=T;c++){
		int n,d;
		scanf("%d%d",&n,&d);
		int Bleft=0,Bright=0,cnt=0,ans=0;
		vector<int> small;
		for(int i=0;i<=n;i++){
			char c;
			int pos;
			if(i==n) {c='B';pos=d;}
			else scanf(" %c-%d",&c,&pos);

			if(c=='B') {
				Bright=pos;
				if(cnt<=1){
					ans=max(ans,Bright-Bleft);
				}
				else{
					int Max=small[1]-Bleft;
					for(int i=0;i<cnt-2;i++){
						if(small[i+2]-small[i]>Max) {
							Max=small[i+2]-small[i];
						}
					}
					ans=max(ans,max(Max,Bright-small[cnt-2]));
				}
				Bleft=Bright;
				cnt=0;
				small.clear();
			}
			else{
				cnt++;
				small.push_back(pos);
			}
		}
		printf("Case %d: %d\n",c,ans);
	}
	return 0;
}