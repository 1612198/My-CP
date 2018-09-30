#include <bits/stdc++.h>
using namespace std;
int n=4;
int d[4][4]={{0,20,42,35},{20,0,30,34},{42,30,0,12},{35,34,12,0}};
int f[4]={0};
vector<int> p(1,0);
int backtrack(int id){
	if(id==n){
		return d[0][p[p.size()-1]];
	}
	else{
		for(int i=1;i<=3;i++){
			if(f[i]==0){
				f[i]=1;
				p.push_back(i);
				return d[i][p[p.size()-2]]+backtrack(id+1);
				f[i]=0;
				p.pop_back();
			}
		}

	}
}	

int main()
{
	//input nhu trog sach
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++)
			cerr<<d[i][j]<<" ";
		cerr<<endl;
	}

	int path[5]={0,1,2,3,0};
	int ans=1e9;
	int sum=0;
	do{
		for(int i=0;i<4;i++)
			sum+=d[path[i]][path[i+1]];
		ans=min(ans,sum);
		sum=0;
	}while(next_permutation(path+1,path+4));

	printf("%d\n",ans);

	int ans2=backtrack(1);
	printf("%d\n",ans2);

	return 0;
}