#include <bits/stdc++.h>
using namespace std;

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int nb,ns; //number of bachelor, number of spinsters
	int c=0;
	while(scanf("%d%d",&nb,&ns),nb||ns){
		int b[nb],s[ns];
		for(int i=0;i<nb;i++){
			scanf("%d",b+i);
		}
		for(int i=0;i<ns;i++){
			scanf("%d",s+i);
		}
		printf("Case %d: ",++c);
		if(nb>ns){
			printf("%d",nb-ns);
			sort(b,b+nb);
			printf(" %d\n",b[0]);
		}
		else printf("0\n");

	}


	return 0;
}