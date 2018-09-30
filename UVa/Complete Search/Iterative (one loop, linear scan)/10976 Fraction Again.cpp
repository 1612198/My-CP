#include <bits/stdc++.h>
using namespace std;

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int k;
	while(scanf("%d",&k)!=EOF){
		double x,y;
		vector<pair<int,int>> pii;
		for(int y=k+1;y<=2*k;y++){
			if(y*k%(y-k)==0){
				pii.push_back(make_pair(y*k/(y-k),y));
			}
		}
		printf("%lu\n",pii.size());
		for(int i=0; i<pii.size(); i++){
			printf("1/%d = 1/%d + 1/%d\n",k,pii[i].first,pii[i].second);
		}
	}
	

	return 0;
}