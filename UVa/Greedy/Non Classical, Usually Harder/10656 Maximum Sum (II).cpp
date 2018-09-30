#include <bits/stdc++.h>
using namespace std;

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int n;
	while(scanf("%d",&n),n){
		vector<int> sub;
		int tmp;
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			if(tmp!=0){
				sub.push_back(tmp);
			}
		}
		if(sub.size()>0){
			printf("%d",sub[0]);
			for(int i=1;i<sub.size();i++)
				printf(" %d",sub[i]);
		}
		else printf("0");
		printf("\n");
	}

	return 0;
}