#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n;
vector<vi> adjList;
vi dfs_num,dfs_low, artiVertex, dfs_parent;
int dfs_count,dfsRoot,rootChildren;

void ArticulationPoint(int u){
	cerr<<"zo\n";
	xuatnum();
	dfs_low[u]=dfs_num[u]=dfs_count++;
	for(int j=0;j<(int)adjList[u].size();j++){
		int v=adjList[u][j];
		if(dfs_num[v]==-1){  //unvisited	
			cerr<<"zo2\n";
			dfs_parent[v]=u;
			if(u==dfsRoot) rootChildren++;  //
			ArticulationPoint(v);
			//lúc này là nó gọi xog hết rồi, tức là tính xong low ở khu vực đó
			//và u > v (u ancestor v)
			if(dfs_low[v]>= dfs_num[u])  //chỉ có 1 path là phải đi qua u 
				artiVertex[u]=1;
			dfs_low[u]=min(dfs_low[u],dfs_low[v]); //TH u is AP thì k đổi nhưng nếu u ko là AP thì có nghĩ là low v < num u => có thể u đi theo path thông qua v sẽ ngắn hơn
		}
		else if(v!=dfs_parent[u])  //v ancestor u (ông trở lên) ~ back edge not circul
				dfs_low[u]=min(dfs_low[u],dfs_num[v]);
		
	}
}

void xuat(){
	for(int i=1;i<=n;i++){
		cerr<<":";
		for(int j=0;j<adjList[i].size();j++)
			cerr<<adjList[i][j]<<" ";
		cerr<<endl;
	}
}
void xuatnum(){
	cerr<<"dfs_num : ";
	for(int i=1;i<=n;i++)
		cerr<<dfs_num[i]<<" ";
	cerr<<endl;
}
int main()
{
	freopen("00315 in.txt","r",stdin);
	freopen("00315 out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	while(1){
		cin>>n;
		if(n==0) break;
		// cout<<"n="<<n<<endl;
		stringstream ss;
		string line;
		adjList.assign(105,vi(0));
		int v, next;
		cin.ignore();  //lượt bỏ "\n" do cin trên kia nó ko get mà getline thì nó ôm trọn
		while(1){
			// ss.str("");
			ss.clear();
			getline(cin,line);
			if(line=="0") break;
			ss<<line;
			ss>>v;
			while(ss>>next){
				adjList[v].push_back(next);
				adjList[next].push_back(v);
			}
			//initial
			
		}
		dfs_num.assign(105,-1);
		dfs_low.assign(105,0);
		dfs_parent.assign(105,0);
		artiVertex.assign(105,0);
		dfs_count=0;
		xuatnum();
		for(int i=1;i<=n;i++){
			if(dfs_num[i]==-1){
		// 		cerr<<"zo0\n";
				dfsRoot=i;
				rootChildren=0;
				ArticulationPoint(i);
				artiVertex[dfsRoot]=(rootChildren>1);
			}
		}
		// ArticulationPoint(1);
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=artiVertex[i];
		for(int i=1;i<=n;i++)
			cerr<<artiVertex[i]<<" ";
		cout<<ans<<endl;
		// xuat();
	}

	return 0;
}