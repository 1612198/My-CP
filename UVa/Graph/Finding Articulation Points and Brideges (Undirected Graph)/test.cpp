#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int no_of_server;
vector<vi> adjList;
vi dfs_num,dfs_low,dfs_parent;
int dfsRoot,rootChildren,dfs_count;
vector<pair<int,int>> ans;
void bridge (int u){
	dfs_low[u]=dfs_num[u]=dfs_count++;
	for(int j=0;j<(int)adjList[u].size();j++){
		int v=adjList[u][j];
		if(dfs_num[v]==-1){
			dfs_parent[v]=u;
			if(u==dfsRoot) rootChildren++;
			bridge(v);
			if (dfs_low[v]>dfs_num[u]){  //trong này thì u ancestor of v
				int x=u, y=v;
				if(x>y) swap(x,y);
				ans.push_back(make_pair(x,y));
			}
			dfs_low[u]=min(dfs_low[u],dfs_low[v]);

		}
		else if(v!=dfs_parent[u])  //v đã thăm rồi => v ancestor of u
				dfs_low[u]=min(dfs_low[u],dfs_num[v]);
	}

}

int main()
{

	while(cin>>no_of_server){
		// cin>>no_of_server;
		cin.ignore();
		// if(no_of_server==0) break;
		adjList.assign(105,vi(0));
		stringstream ss;
		string line;
		int server,num,next;
		for(int i=0;i<no_of_server;i++){
			getline(cin,line);
			ss.clear();
			ss<<line;
			string tmp;
			ss>>server>>tmp;
			tmp.erase(tmp.begin());
			tmp.erase(tmp.end()-1);
			num=stoi(tmp);
			while(num--){
				ss>>next;
				adjList[server].push_back(next);
			}
		}

		//initial
		dfs_num.assign(105,-1); //-1 = unvisited
		dfs_low.assign(105,0);
		dfs_count=0;
		dfs_parent.assign(105,-1); //vì vertex tính từ 0->no_of_server-1
		for(int i=0;i<no_of_server;i++){
			if(dfs_num[i]==-1){
				dfsRoot=i;
				rootChildren=0;
				bridge(i);
			}
		}
		sort(ans.begin(),ans.end());
		cout<<ans.size()<<" critical links\n";
		for(int i=0;i<ans.size();i++){
			cout<<ans[i].first<<" - "<<ans[i].second<<"\n";
		}
		cout<<"\n";
		ans.resize(0);
	}

	return 0;
}