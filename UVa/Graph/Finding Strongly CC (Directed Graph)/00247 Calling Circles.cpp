#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n,m;
map<string,vector<string>> adjList;
map<string,int> dfs_num,dfs_low,visited;
vector<string> S;
int dfs_count;
void tarjanSCC(string u){
	dfs_low[u]=dfs_num[u]=dfs_count++;
	S.push_back(u);
	visited[u]=1;
	for(int j=0;j<(int)adjList[u].size();j++){
		string v=adjList[u][j];
		if(dfs_num[v]==0)  //unvisited
			tarjanSCC(v);
		if(visited[v]==1)
			dfs_low[u]=min(dfs_low[u],dfs_low[v]);
	}	
	if(dfs_low[u]==dfs_num[u]){
		while(1){
			string v=S.back();
			S.pop_back();
			visited[v]=0;
			cout<<v;
			if (u==v) break;
			cout<<", ";
		}
		cout<<endl;
	}

}

void xuat(){
	map<string,vector<string>>::iterator it;
	for(it=adjList.begin();it!=adjList.end();it++){
		cerr<<it->first<<" : ";
		for(int j=0;j<it->second.size();j++)
			cerr<<it->second[j]<<" ";
		cerr<<endl;
	}
	for(it=adjList.begin();it!=adjList.end();it++){
		cerr<<dfs_num[it->first]<<" ";
	}
	cerr<<endl;
}
void init(){
	map<string,vector<string>>::iterator it;
	for(it=adjList.begin();it!=adjList.end();it++){
		dfs_num[it->first]=dfs_low[it->first]=visited[it->first]=0;
	}
	dfs_count=1; //0 la unvisited
	S.resize(0);
}


int main()
{
	freopen("00247 in.txt","r",stdin);
	freopen("00247 out.txt","w",stdout);
	int c=1;
	while(scanf("%d %d",&n,&m),n||m){
		string a,b;
		while(m--){
			cin>>a>>b;
			adjList[a].push_back(b);
			adjList[b];
		}
		map<string,vector<string>>::iterator it;
		for(it=adjList.begin();it!=adjList.end();it++){
			set<string> s(adjList[it->first].begin(),adjList[it->first].end());
			it->second.resize(0);
			it->second=vector<string>(s.begin(),s.end());
		}
		init();
		xuat();
		cout<<"Calling circles for data set "<<c++<<":\n";
		for(map<string,vector<string>>::iterator it=adjList.begin();it!=adjList.end();it++){
			if(dfs_num[it->first]==0)
				tarjanSCC(it->first);
		}
		cout<<endl;
	}
	// xuat();

	return 0;
}