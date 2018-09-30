//vì độ rộng chỉ có 3 nên nó cục bộ theo mỗi grow area
#include <bits/stdc++.h>
using namespace std;

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int c=1;c<=T;c++){
		int n;
		scanf("%d",&n);
		string s;
		cin>>s;
		// s+="#";  //kĩ thuật lính canh cho vòng while
		int cur=-1;
		int i=0;
		int ans=0;
		while(i<n){
			if(s[i]=='.' && i>cur) {cur=i+2; ans++;} //đặt scarecrow ở i+1 thì cur=rightmost=i+2
			i++;
		}
		printf("Case %d: %d\n",c,ans);
	}

	return 0;
}