#include <bits/stdc++.h>
using namespace std;

int main(){
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	string s;  //kí tự ở sau có thể lặp lại kí tự ở trước
	cin>>s;
	map<char, vector<int>> m;
	for(int i=0; i<s.size();i++){
		m[s[i]].push_back(i);
	}
	int n;
	cin>>n;
	while(n--){
		string q;
		cin>>q;
		int p=-1;
		bool found=true;
		int first=-1, last=-1;
		for(int i=0; i<q.size();i++){
			char c=q[i];
			auto it=lower_bound(m[c].begin(),m[c].end(),p+1);
			if(it==m[c].end()){
				found=false;
				break;
			}
			p=*it;  //kí tự sau phải có serial lớn hơn trước.
			if(first==-1) first=p;
			last=p;
		}
		if(found){
			printf("Matched %d %d\n",first,last);
		}else{
			printf("Not matched\n");
		}
	}

	return 0;
}