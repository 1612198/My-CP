#include <bits/stdc++.h>
using namespace std;

int m,n;
int p[105],f[105];
int memo[105][11005]; //nho memset
// int oneTime=1;

int ff(int id,int w){
	if(w>m && m<=1800) return -1000; //min để ra + vs tất cả f[id] từ trước thì vẫn âm, nghĩa là con đưòng này vô vọng
	if(w>m+200) return -1000;
	if(id==n) {
		if(w>m && w<=2000) return -1000;
		return 0;
	} 
	int& ret=memo[id][w];
	if(ret!=-1) return ret;
	return ret=max(ff(id+1,w),f[id]+ff(id+1,w+p[id]));
}



int main()
{
	freopen("10819 in.txt","r",stdin);
	freopen("10819 out.txt","w",stdout);
	while(scanf("%d%d",&m,&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d %d",p+i,f+i);
		memset(memo,-1,sizeof memo);
		// oneTime=1;
		printf("%d\n",ff(0,0));
		// cerr<<"m="<<m<<endl;
	}


	return 0;
}