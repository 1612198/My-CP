#include <bits/stdc++.h>
using namespace std;
int cd_length,n,track[30];
int top=0;
int cd[30],optimum_cd[30],optimum_top,minimum_space,sum=0;


void max_length(int minutes,int index){
	if(minutes-track[index]<0||index==n){
		if(minutes<minimum_space){
			optimum_top=top;  //~number of tracks
			minimum_space=minutes;
			for(int i=0;i<top;i++) optimum_cd[i]=cd[i];
		}	
	}
	else{
		cd[top++]=track[index];  //(*)
		for(int i=index+1;i<=n;i++){
			max_length(minutes-track[index],i);
		}
		top--;
	}
}
// (*): Mỗi phần tử i=0 ta ghép với i=1->n 
// 	 Mỗi phần tử i=1 (trong 1->n) ta ghép với i=2->n
// 	 Mỗi phần tử i=2 (trong 2->n) ta ghép với i=3->n
// 	 Xong rồi ta làm tiếp lệnh tiếp theo là i=0 ghép với i=2 (trong 1->n)
// 	 Mỗi i=2 ở trên lại ghép với mỗi i từ 3->n
// 	 => Có rất nhiều dòng for lồng nhau. O(n!) 


int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	while(scanf("%d %d",&cd_length,&n)!=EOF){
		for(int i=0; i<n;i++){
			scanf("%d",track+i);
		}
		minimum_space=cd_length;
		for(int i=0;i<n;i++)
			max_length(cd_length,i);
		int best=0;
		for(int i=0;i<optimum_top;i++){
			best+=optimum_cd[i];
			printf("%d ",optimum_cd[i]);
		}
		printf("sum:%d\n",best);
	}

	return 0;
}