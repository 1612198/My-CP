#include <bits/stdc++.h>
using namespace std;

int s,d;  //surplus, deficit
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&s,&d)!=EOF){
		int nd;
		for(nd=1;nd<=5;nd++)
			if((s*(5-nd)-nd*d)<0) break;
		int nd12=2*nd+max(0,nd-3);
		int ans=s*(12-nd12)-d*nd12;
		if(ans>=0) printf("%d\n",ans);
		else printf("Deficit\n");
	}

	return 0;
}
//Mình đâu cần backtrack đâu nhỉ? :'(