-- Trong directed Graph, SCC (Strongly Connected Component) được 
quan tâm nhiều
1 tập các vertices (v1,v2,..vn) là 1 SCC nếu với mọi 2 vertices 
chọn ra trong tập luôn có path đi từ vx->vy và vy->vx,, tạo 
thành 1 cycle
- Nếu có 2 SCC dính lẹo, thì tính 1 nhé, chạy 1 ví dụ sẽ rõl.

typedef vector<int> vi;
vi dfs_num, dfs_low, S, visited;

void tarjanSCC(int u){
	dfs_low[u]=dfs_num[u]=dfsCounter++;
	S.push_back(u);
	visited[u]=1;
	for(int j=0;j<(int)adjList[u].size();j++){
		ii v = adjList[u][j];
		if(dfs_num[v.first]==UNVISITED)
			tarjanSCC(v.first);
		if(visited[v.first]) //update low, giống AP&Bridge thôi
			dfs_low[u]=min(dfs_low[u],dfs_low[v.first]);
	}
	if (dfs_low[u]==dfs_num[u]){
		printf ("SCC %d:",++numSCC);
		while(1){
			int v=S.back();
			S.pop_back();
			visited[v]=0;
			printf (" %d",v);
			if (u==v) break;
		}
		printf ("\n");
	}
}
//inside int main()
	dfs_num.assign(V,UNVISITED);
	dfs_low.assign(V,0);
	visited.assign(V,0);
	dfsCounter=numSCC=0;
	for(int i=0;i<V;i++)
		if(dfs_num[i]==UNVISITED)
			tarjanSCC(i);