//kí hiệu trên dưói nó có hơi mâu thuẫn xí (dm steven halim)
#include <bits/stdc++.h>
using namespace std;

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);

	int g,money,k,TC,M,C;
	int price[25][25];
	bool reachable[25][210]; //reachable table[g<=20][money<=200]
	scanf("%d",&TC);
	while(TC--){
		scanf("%d %d",&M,&C);
		// cerr<<M<<" "<<C<<endl;
		for(g=0;g<C;g++){
			scanf("%d",&price[g][0]);
			for(money=1;money<=price[g][0];money++){
				scanf("%d",&price[g][money]);
			}
		}
		// for(int i=0;i<C;i++){
			// for(int j=1;j<=price[i][0];j++)
				// cerr<<price[i][j]<<" ";
			// cerr<<endl;			
		// }
			
		memset(reachable,false,sizeof reachable);
		for(g=1;g<=price[0][0];g++)  //initial values (base cases)
			if(M-price[0][g]>=0)//sau khi mua mẫu g của loại 0 thì số tiền còn lại là M-price[0][g] 
				reachable[0][M-price[0][g]]=true; //kĩ thuật tận dụng chỉ số reachable
		for(g=1;g<C;g++){
			for(money=0;money<M;money++){ //do đã mua model ở garment 0 nên số tiền còn lại ko thể đạt tới M vì price > 0
				if(reachable[g-1][money]==true) //money: số tiền còn lại sau khi đã mua xong model (đéo biết) ở garment g-1 (bắt đầu garment 0)
					for(k=1;k<=price[g][0];k++){
						if(money-price[g][k]>=0)
							reachable[g][money-price[g][k]]=true;
					}
			}
		}
		// for(int i=0;i<C;i++){
		// 	for(int j=0;j<M;j++){
		// 		cerr<<reachable[i][j]<<" ";
		// 	}
		// 	cerr<<endl;
		// }
		// cerr<<C<<endl;
		for(money=0;money<M;money++){
			if(reachable[C-1][money]) break;
		}
		// cerr<<money<<endl;
		if(money<M) printf("%d\n",M-money);
		else printf("no solution\n");
	}

	return 0;
}