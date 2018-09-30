Ý tưởng:
1. Brute Force:
	Quét qua từng node, cắt bỏ nó và các cạnh liên quan, nếu điều đó
	làm tăng số CC thì nó chính là AP, k thì ko phải.
2. Dùng DFS tree + dfs_low, dfs_time, dfs_parent
							(dfs_num)
** AP (articulation Point) is vertex
** Bridge is Edge
Both removal disconnects G.

void articulationPointAndBridge (int u){
	dfs_low[u]=dfs_num[u]=dfsNumberCounter++; //dfs_low[u]<=dfs_num[u]
	for (int j=0;j<(int)AdjList[u].size();j++){
		ii v=AdjList[u][j];
		if(dfs_num[v.first]==UNVISITED){   //a tree edge vd -1-> UNVISITED, >=0: VISITED
			dfs_parent[v.first]=u;
			if(u==dfsRoot) rootChildren++;  //special case if u is a root
			
			articulationPointAndBridge(v.first);
			if(dfs_low[v.first]>=dfs_num[u]) //so sánh với num vì num là cái ko đổi theo thứ tự duyệt còn low có thể updated, nên tại thời điểm đó phải so vs num vì ta đang đi theo thứ tự duyệt đó.
				articulation_vertex[u]=true;
			if(dfs_low[v.first]>dfs_num[u])
				printf ("Edge (%d,%d) is a bridge\n",u,v.first);
			dfs_low[u]=min(dfs_low[u],dfs_low[v.first]);  //update dfs_low[u]
		}
		else if (v.first!=dfs_parent[u])   //a back edge and not direct cycle
			dfs_low[u]=min(dfs_low[u],dfs_num[v.first]); //update dfs_low[u]
	}
}	

//inside int main()
	dfsNumberCounter=0;
	dfs_num.assign(V,UNVISITED);
	dfs_low.assign(V,0);
	dfs_parent.assign(V,0);
	articulation_vertex.assign(V,0);
	printf("Bridges:\n");
	for (int i=0;i<V;i++){
		if(dfs_num[i]==UNVISITED){
			dfsRoot=i;
			rootChildren=0;
			articulationPointAndBridge(i);
			articulation_vertex[dfsRoot]=(rootChildren>1);
		}
		printf ("Articulation Points:\n");
		for(int i=0;i<V;i++)
			if(articulation_vertex[i])
				printf(" Vertex %d\n",i);
	}

** Vì sao trên min (lowU,lowV), dưới min(lowU,numV)
chạy ví dụ                 *  sẽ rõ
						  /| 
						 * |
						/ \| 
					   *---*
khi 1 vertex update low nó sẽ lan ra  những thằng connect với nó, 