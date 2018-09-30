#include <bits/stdc++.h>
using namespace std;

int v,n;
int a[1000];
	
int memo[1000];
int change(int v){
	if(v==0) return 0;
	if(v<0) return 1e9; //con đường vô nghĩa
	int& ret=memo[v];
	if(ret!=-1) return ret;
	int ans=1e9; //kết nối các TH lại
	for(int i=0;i<n;i++){
		ans=min(ans,change(v-a[i])+1);
	}
	return ans;
}

int main()
{
	freopen("CC in.txt","r",stdin);
	scanf("%d %d\n",&v,&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	
	memset(memo,-1,sizeof memo);
	int ans=change(v);
	printf("%d\n",ans);
	return 0;
}