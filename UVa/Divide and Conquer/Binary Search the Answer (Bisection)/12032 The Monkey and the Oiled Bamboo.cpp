#include <bits/stdc++.h>
using namespace std;
		
int n;
int h[10010];
//xét các trường hợp phủ định, tức là return false
bool can(int k){
	if(h[0]==k) k--;
	for(int i=1;i<n;i++){
		if(h[i]-h[i-1]>k) return false;
		if(h[i]-h[i-1]==k) k--;
		if(k<0) return false;
	}
	return true;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	clock_t t=clock();
	int T;
	scanf("%d",&T);
	for(int c=1;c<=T;c++){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",h+i);
		int max_distance=h[0];
		for(int i=0;i<n-1;i++)
			if(h[i+1]-h[i]>max_distance) max_distance=h[i+1]-h[i];
			// max_distance=max(max_distance,h[i+1]-h[i]);
		// => k thuộc [max_distance; 1e7 ]
		int lo=max_distance,hi=1e7;
		while(lo<hi){
			int mid=(lo+hi)/2;
			if(can(mid)){  //mid nhỏ nhất thỏa
				hi=mid;
			}else{
				lo=mid+1;
			}
		}
		printf("Case %d: %d\n",c,hi);
	}
	t=clock()-t;
	cerr<<"Time = "<<(double)t/CLOCKS_PER_SEC;
	return 0;
}