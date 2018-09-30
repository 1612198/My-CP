#include <bits/stdc++.h>
using namespace std;

int T;
vector<int> nodes;
vector< vector<int> > edges;  //phai la vector, vd TH A<B, A<C, B<C
vector<bool> visited;
bool flag;
//edges[p]: ds những cái việc phải thực hiện sau p
bool valid(){
	int p,q;
	for(int i=0;i<nodes.size();i++){
		p=nodes[i];
		if(!visited[p]){
			for(int j=0;j<edges[p].size();j++){
				q=edges[p][j];
				if(visited[q]) return false;
			}
		}
	}
	return true;
}

void tps(vector<int> &ans){
	if(ans.size()==nodes.size()){
		flag=true;
		for(int i=0;i<nodes.size();i++){
			if(i) cout<<" ";
			cout<<char(ans[i]+'A');
		}
		cout<<endl;
		return;
	}

	int p,q;
	for(int i=0;i<nodes.size();i++){
		p=nodes[i];
		if(!visited[p]){
			visited[p]=true;  //gỉa sử thăm nó rồi ms xét hợp lệ hay ko chứ
			if(valid()){
				ans.push_back(p);
				tps(ans);
				ans.pop_back();
			}
			visited[p]=false;
		}
	}
}


int main()
{
	// freopen("00872 in.txt","r",stdin);
	cin>>T;
	cin.ignore();  //ignore()\n after cin integer T
	string str;
	stringstream ss;
	vector<int> ans;

	while(T--){
		getline(cin,str);  //read the blank line

		nodes.clear();
		edges.assign(26,vector<int> (0));
		ans.clear();
		visited.assign(26,false);

		getline(cin,str);
		ss.clear();
		ss.str("");
		ss<<str;
		char ch; int letter;
		while(ss>>ch){
			letter=ch-'A';
			nodes.push_back(letter);
		}

		getline(cin,str);
		ss.clear();
		ss.str("");
		ss<<str;

		char ch1,op,ch2; int letter1,letter2;
		while(ss>>ch1>>op>>ch2){
			letter1=ch1-'A';
			letter2=ch2-'A';
			edges[letter1].push_back(letter2);
		}
		// xuat();
		flag=false;
		tps(ans);
		if(!flag) cout<<"NO\n";
		if(T) cout<<endl;
	}


	return 0;
}

/*
	Vấn đề ở đây là generate all topological ordering.
	
*/