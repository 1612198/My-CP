#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int C, nS;
	int set=1;
	while(scanf("%d%d",&C,&nS)!=EOF){
		int S[11]={0};
		int sum=0;
		for(int i=0;i<nS;i++){
			scanf("%d",&S[i]);
			sum+=S[i];
		}
		sort(S,S+2*C);
		for(int i=0;i<2*C;i++){
			cerr<<S[i]<<" ";
		}
		cerr<<endl;
		double A=sum*1.0/C;
		double imb=0;
		printf("Set #%d\n",set++);
		for(int i=0;i<C;i++){
			imb+=abs(S[i]+S[2*C-i-1]-A);
			printf("%2d:",i);
			if(S[i]) printf(" %d",S[i]);
			if(S[2*C-i-1]) printf(" %d",S[2*C-i-1]);
			printf("\n");
		}
		printf("IMBALANCE = %.5lf\n\n",imb);
	}
	return 0;
}