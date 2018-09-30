#include <bits/stdc++.h>
using namespace std;

int n,S;
int memo[1000][1000];
int V[1000],W[1000];
int val(int id,int remW){
	if(id==n || remW==0) return 0;
	if(memo[id][remW]!=-1) return memo[id][remW];
	if(W[id]>remW) return memo[id][remW]=val(id+1,remW);
	return memo[id][remW]=max(val(id+1,remW),V[id]+val(id+1,remW-W[id]));
}

int main()
{
	freopen("0-1 Knapsack_in.txt","r",stdin);
    freopen("0-1 Knapsack_out.txt","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d",V+i);
	for(int i=0;i<n;i++)
		scanf("%d",W+i);
	cin>>S;
	for(int i=0;i<n;i++)
		cerr<<V[i]<<" ";
	cerr<<endl;
	for(int i=0;i<n;i++)
		cerr<<W[i]<<" ";
	cerr<<endl;
	cerr<<S<<endl;
	memset(memo,-1, sizeof memo);
	int ans=val(0,S);
	printf("%d\n",ans);

	for(int i=0;i<n;i++){
		for(int m=0;m<=S;m++){
			cerr<<memo[i][m]<<" ";
		}
		cerr<<endl;
	}

	return 0;
}