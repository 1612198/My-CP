#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int nmax = 1e4+4;

int n,m;
vector<vi> adjList;
vi dfs_low, dfs_num, dfs_parent, addCC;  //số CC tạo ra thêm khi remove AP
int dfsRoot, rootChildren, dfs_count;

void articulationPoint(int u){
	dfs_low[u]=dfs_num[u]=dfs_count++;
	for(int j=0;j<adjList[u].size();j++){
		int v=adjList[u][j];
		if(dfs_num[v]==-1){
			dfs_parent[v]=u;
			if(u==dfsRoot) rootChildren++;
			articulationPoint(v);
			if(dfs_low[v]>=dfs_num[u]) 
				addCC[u]++;
		}
		else if(v!=dfs_parent[u])
				dfs_low[u]=min(dfs_low[u],dfs_num[v]);
	}
}

bool cmp(pair<int,int> a,pair<int,int> b){
	if (a.second==b.second) return a.first<b.first;
	return a.second > b.second;
}

void xuat(){
	for(int i=0;i<n;i++){
		cerr<<i<<" : ";
		for(int j=0;j<adjList[i].size();j++)
			cerr<<adjList[i][j]<<" ";
		cerr<<endl;
	}
}


int main()
{
	freopen("10765 in.txt","r",stdin);
	freopen("10765 out.txt","w",stdout);

	while(scanf("%d%d",&n,&m),n||m){
		int x,y;
		adjList.assign(nmax,vi(0));
		while(scanf("%d%d",&x,&y),x!=-1){
			adjList[x].push_back(y);
			adjList[y].push_back(x);
		}
		// xuat();
		//initial
		int numCC=0;
		dfs_low.assign(nmax,0);
		dfs_num.assign(nmax,-1);
		dfs_parent.assign(nmax,-1);
		addCC.assign(n,0);
		addCC.resize(n);
		for(int i=0;i<n;i++){
			if(dfs_num[i]==-1){
				dfs_count=0;
				numCC++;
				dfsRoot=i;
				rootChildren=0;
		 		articulationPoint(i);
				addCC[i]=rootChildren-1; //khi remove root
			}
		}
		vector<pair<int,int>> ans;
		for(int i=0;i<n;i++){
			ans.push_back(make_pair(i,numCC+addCC[i]));
		}
		// sort(ans.begin(),ans.end(),std::greater<pair<int,int>>());
		sort(ans.begin(),ans.end(),cmp);

		for(int i=0;i<m;i++){
			printf("%d %d\n",ans[i].first,ans[i].second);
		}
		printf("\n");
	}

	return 0;
}

/*
	1. Trong 1 circal chỉ duy nhất 1 lần AP được tích 1. Nghĩa là 
	ta có thể lợi dụng điều đó để count number of cc, cùng với nhánh
	đàu vào nó nữa, tức là CC vốn có của Graph
*/