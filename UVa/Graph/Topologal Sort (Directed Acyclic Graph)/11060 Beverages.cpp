//Khác bọt: In the case there is no relation between 2 beverages
//Dilbert should start drinking the one that appears first in
//the input
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<string> bev;   //store all bevarages with order input
map<string,int> indegree;  
map<string,vector<string> > adjList;

void xuat(){
	for(int i=0;i<n;i++){
		cerr<<bev[i]<<" has indgree = "<<indegree[bev[i]]<<endl;
	}
	cerr<<endl;
	cerr<<"Adj list: \n";
	for(int i=0;i<n;i++){
		cerr<<bev[i]<< " -- ";
		for(int j=0;j<adjList[bev[i]].size();j++){
			cerr<<adjList[bev[i]][j]<<" ";
		}
		cerr<<endl;
	}
}
int main()
{
	freopen("11060 in.txt","r",stdin);
	freopen("11060 out.txt","w",stdout);
	int c =0;

	while(cin>>n){
		bev.clear();
		indegree.clear();
		adjList.clear();

		string str;
		for(int i=0;i<n;i++){
			cin>>str;
			bev.push_back(str);
		}
		cin>>m;
		string str1;
		for(int i=0;i<m;i++){
			cin>>str>>str1;
			indegree[str1]++;
			adjList[str].push_back(str1);
		}
		// xuat();
		queue<string> q;
		int i=0;
		while(indegree[bev[i]]>0){i++;}
		q.push(bev[i]);
		vector<string> u1=adjList[bev[i]];
		for(int j=0;j<u1.size();j++){
			indegree[u1[j]]--;
		}
		bev.erase(bev.begin()+i);
		vector<string> tp;

		while(!q.empty()){
			string p=q.front();
			q.pop();
			tp.push_back(p);
			int i=0;
			while(indegree[bev[i]] && i<bev.size()){i++;}
			if(i==bev.size()) break;
			q.push(bev[i]);  //push into queue cái có indegree=0
			vector<string> u=adjList[bev[i]];
			for(int j=0;j<u.size();j++){
				--indegree[u[j]]; //descrease all nodes connect with node pushed
			}

			bev.erase(bev.begin()+i);	//erase node from input
		}
		cout<<"Case #"<<++c<<": Dilbert should drink beverages in this order:";
		for(int j=0;j<tp.size();j++){
			cout<<" "<<tp[j];
		}
		cout<<"."<<endl;
		cout<<endl;

	}
	return 0;
}