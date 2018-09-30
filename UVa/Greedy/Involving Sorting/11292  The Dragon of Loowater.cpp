#include <bits/stdc++.h>
using namespace std;

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int n,m;
	while(scanf("%d%d",&n,&m),m||n){
		int dia[n], hei[m];
		for(int i=0;i<n;i++)
			scanf("%d",dia+i);
		for(int i=0;i<m;i++)
			scanf("%d",hei+i);
		sort(dia,dia+n);
		sort(hei,hei+m);
		int j=0,cnt=0;
		int ans=0;
		for(int i=0;i<n;i++){
			while(hei[j]<dia[i] && j<m) j++;
			if(j==m) break;
			else{
				ans+=hei[j];
				j++; cnt++;
			}
			if(cnt==n) break;
		}
		if(cnt<n) printf("Loowater is doomed!\n");
		else printf("%d\n",ans);
	}

	return 0;
}