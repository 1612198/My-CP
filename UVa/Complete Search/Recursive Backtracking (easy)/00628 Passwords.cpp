#include <bits/stdc++.h>
using namespace std;

int nword,nrule;
vector<string> word,rule;
vector<string> pass;
vector<string> ans;
void password(int pos,string rule){
	if(pos==rule.size()){
		string tmp="";
		for(int i=0; i<pass.size();i++) tmp+=pass[i];
		ans.push_back(tmp);
	}
	else{
		if(rule[pos]=='#') {
			for(int i=0; i<nword; i++){
				pass.push_back(word[i]);
				pos++;
				password(pos,rule);
				pos--;
				pass.pop_back();
			}
		}
		else {
			for(int i=0;i<10;i++){
				pass.push_back(to_string(i));
				pos++;
				password(pos,rule);
				pos--;
				pass.pop_back();
			}
		}
	}
}

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	while(scanf("%d",&nword)!=EOF){
		word.resize(nword);
		for(int i=0; i<nword; i++){
			cin>>word[i];
		}
		scanf("%d",&nrule);
		rule.resize(nrule);
		for(int i=0; i<nrule; i++)
			cin>>rule[i];
		ans.resize(0);
		for(int i=0; i<nrule; i++){
			password(0,rule[i]);
		}
		cout<<"--\n";
		for(int i=0; i<ans.size(); i++){
			cout<<ans[i]<<endl;
		}
	}


	return 0;
}