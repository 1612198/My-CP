#include <bits/stdc++.h>
using namespace std;

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		vector<int> A(n);
		for(int i=0;i<n;i++){
			scanf("%d",&A[i]);
		}
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=0; j<i; j++){
				if(A[j]<=A[i]) ans++;
			}
		}
		printf("%d\n",ans);
	}


	return 0;
}