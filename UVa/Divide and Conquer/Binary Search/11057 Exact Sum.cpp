#include <bits/stdc++.h>
using namespace std;

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int n;
	while(scanf("%d",&n)!=EOF){
		vector<int> cost(n);
		for(int i=0;i<n;i++) cin>>cost[i];
		int M;
		cin>>M;
		int ans;
		sort(cost.begin(),cost.end());
		for(int i=0; cost[i]<=M/2;i++){
			int x=M-cost[i];
			auto it=lower_bound(cost.begin()+i+1,cost.end(),x); //sử dụng lower_bound và check
			if(x==*it) ans=x;  //phan lon                       //xem có phải dấu = xay ra ko thay vì viết hàm binary search
		}
		cout<<"Peter should buy books whose prices are "<<M-ans<<" and "<<ans<<".\n\n";
	}

	return 0;
}