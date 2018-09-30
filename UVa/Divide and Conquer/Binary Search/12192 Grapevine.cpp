#include <bits/stdc++.h>
using namespace std;

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int rows, cols;
	while(scanf("%d%d",&rows,&cols),rows&&cols){
		int plot[rows][cols];
		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){
				scanf("%d",&plot[i][j]);
			}
		}
		
		int q; //query
		scanf("%d",&q);
		while(q--){
			int L,U;
			scanf("%d %d",&L,&U);
			int max_size=0;
			for(int i=0; i<rows; i++){
				int* lbOfL=lower_bound(plot[i],plot[i]+cols,L);
				int left_index=lbOfL-plot[i]; //~iterator
				for(int sz=0; sz<rows; sz++){  //<rows || <cols như nhau vì sau ta xét đk break trước rồi, sz: size ta thử nghiệm
					if(left_index+sz>=cols||i+sz>=rows || plot[i+sz][left_index+sz]>U) break;  //chụp vào nguyên khung rowsxrows đến khi nào dư thì break; vậy cho tiện
					if(sz+1>max_size) max_size=sz+1;
				}
			}
			printf("%d\n",max_size);
		}
		printf("-\n");
	}

	return 0;
}