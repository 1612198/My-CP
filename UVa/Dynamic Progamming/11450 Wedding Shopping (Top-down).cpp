#include <bits/stdc++.h>
using namespace std;

int M,C, price[25][25]; //price[g<=20][model<=20];
int memo[210][25]; //TOP-DOWN: dptable memo[money<=200][g<=20];

int shop(int money,int g){ 
	if(money<0) {cerr<<"am\n";return -1e9;}
	if(g==C) {cerr<<"dich\n";return M-money;}  //chọn xong rồi, tiền đã sài =M(ban đầu) - tiền còn lại(money)
	if(memo[money][g]!=-1){cerr<<"trung\n"; return memo[money][g];}
	int ans=-1;
	for(int model=1;model<=price[g][0];model++){
		ans=max(ans,shop(money-price[g][model],g+1)); //mua tối ưu tại từng garment luôn
		cerr<<"garment = "<<g<<" ans = "<<ans<<endl;
	}
	return memo[money][g]=ans; //TOP-DOWN: memorize ans and return it

}

int main()
{
	freopen("/media/hieudoan7/JOB/ALGORITHMS/MyCP/UVa/in.txt","r",stdin);
    freopen("/media/hieudoan7/JOB/ALGORITHMS/MyCP/UVa/out.txt","w",stdout);
	int TC;
	scanf("%d",&TC);
	while(TC--){
		// cerr<<TC<<endl;
		scanf("%d %d",&M,&C);
		for(int i=0;i<C;i++){
			scanf("%d",&price[i][0]);//firse value save k (number of price each garment)
			for(int j=1;j<=price[i][0];j++) 
				scanf("%d",&price[i][j]);
		}
		memset(memo,-1,sizeof memo); //initialize DP memo table
		int score=shop(M,0);
		if(score<0) printf("no solution\n"); //mua vượt quá thì còn lại âm
		else printf("%d\n",score);		
	}


	return 0;
}