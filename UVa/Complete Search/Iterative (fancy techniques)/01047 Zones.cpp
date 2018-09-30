#include <bits/stdc++.h>
using namespace std;

int count(int a){
	int cnt=0;
	while(a!=0){
		cnt++;
		a-=(a&(-a));  //chạy = tay ra sẽ rõ :v a&(-a) = a&(bù 1) +1
	}
	return cnt;
}
int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int n,actual;
	int tc=1;
	while(scanf("%d%d",&n,&actual), n){
		vector<int> tower(n);
		for(int i=0;i<n;i++){
			scanf("%d",&tower[i]);
		}
		int m;
		scanf("%d",&m);
		int ca[20],inside_ca[20]; //common_area
		memset(inside_ca,0,sizeof(inside_ca));
		int pos; //pos intersection
		int num_pos; //number of tower intersection
		for(int i=0;i<m;i++){
			scanf("%d",&num_pos);
			for(int j=0;j<num_pos;j++){
    			scanf("%d",&pos);
    			inside_ca[i]|=1<<(pos-1); //set bit
    		}
    		scanf("%d",&ca[i]);
    	}
    	//
    	// for(int i=0;i<m;i++) cerr<<inside_ca[i]<<" ";
    	//
    	int best=0,loca;  //best: number of customers, locations recommended
    	for(int i=0;i<(1<<n); i++){
    		if(count(i)==actual){
    			int sum=0;
    			for(int j=0;j<n;j++)
    				if(i&(1<<j)){
    					sum+=tower[j];
    				}
    			for(int j=0;j<m;j++){
    				int numOfCom=i&inside_ca[j]; //number of commond tower
    				if(numOfCom>1){
    					sum-=(count(numOfCom)-1)*ca[j]; //trong đề là những customer được phủ 
    					                               // bởi 2 sẽ không tính vào phủ bởi 3 
    				}
    			}
    			if(sum>best) {
    				best=sum;
    				loca=i;
    			}
    			else 
    				if(sum==best){
    					for(int j=0;j<n;j++){
    						int a=i&(1<<j);
    						int b=loca&(1<<j);
    						// if(a==0 && b>0) {
    						// 	best=sum;
    						// 	loca=i;
    						// }
    						// if(a>0 &&b==0) break; //loại i rồi
    						if(a!=b){ //chắc chắn i hoặc best sẽ được cái tốt hơn
    							if(a>0) {
    								// best=sum;
    								loca=i;
    							}	
    							break;
    						}
    					}
    				}
    		}
    	}
    	printf("Case Number  %d\n",tc++);  //sử dụng rồi mới tăng.
    	printf("Number of Customers: %d\n",best);
    	printf("Locations recommended:");
    	for(int i=0;i<n;i++){  //i=0..n-1 because  //n towers need n bit (bit 0->n-1) represent 
    		if(loca&(1<<i)){
    			printf(" %d",i+1);
    		}
    	}
		printf("\n\n");
	}



    return 0;
}
