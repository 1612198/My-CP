//Bài toán có thể phát biểu lại là nhóm n chai thành m cụm sao cho 
//max của các cụm là nhỏ nhất
#include <bits/stdc++.h>
using namespace std;

int nves, ncon;  //numver of vessels, number of containers
int v[1005]; //volume of vessels

bool can(int vol){
	int cnt=0, cur=0;
	for(int i=0;i<nves;i++){
		if(v[i]>vol) return false;  //nếu có 1 bình có thể tích lớn hơn vol thì vol đương nhiên sai rồi
		if(cur+v[i]>vol) cur=0;    //cur+v[i] >vol thì ta nhóm cur+v[i] thành 1 cluster va đếm số container đã fill,reset vol=0
		if(cur==0) cnt++;
		cur+=v[i];
		if(cnt>ncon) return false;  // số containers đã fill nhiều hơn đề cho thì sai rồi còn gì.
	}
	return true;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&nves,&ncon)!=EOF){
		for(int i=0; i<nves; i++)
			scanf("%d",v+i);
		int lo=0, hi=1e9;
		while(lo<hi){
			int mid=(lo+hi)/2;
			if(can(mid)){
				hi=mid;
			}
			else {  //cannot thì phải tăng mid lên, tức là tăng lo 
				lo=mid+1;
			}
		}
		printf("%d\n",lo);
	}


	return 0;
}