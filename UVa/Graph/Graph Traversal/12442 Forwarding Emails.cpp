#include <bits/stdc++.h>
using namespace std;

int T, N;
vector<int> adjList;
int visited[50005]={0};
int sum[50005];
int dfs(int u){
	visited[u]=1;
	int total=0;
	if(!visited[adjList[u]]){
		total=1+dfs(adjList[u]);
	}
	visited[u]=0;
	return sum[u]=total;
}

int main()
{
	freopen("12442 in.txt","r",stdin);
	freopen("12442 out.txt","w",stdout);

	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d",&N);
		int u,v;
		// adjList.resize(N+2);
		adjList.assign(N+2,-1);
		for(int i=1;i<=N;i++){
			scanf("%d%d",&u,&v);
			adjList[u]=v;  //chắc chắn đề sẽ cho lấp đầy 1->N, nên khỏi lo = -1
		}
		int max=-1,max_id;
		memset(sum,-1,sizeof sum);
		for(int i=1;i<=N;i++){
			if(sum[i]==-1) dfs(i);
			if(sum[i]>max){
				max=sum[i];
				max_id=i;
			}
		}
		printf("Case %d: %d\n",t,max_id);

	}

	return 0;
}