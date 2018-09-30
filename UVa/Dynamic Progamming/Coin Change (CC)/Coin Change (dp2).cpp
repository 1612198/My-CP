#include <bits/stdc++.h>
using namespace std;

int v,n;
int a[1000];
	
#define MAX 1e9

int main()
{
	freopen("CC in.txt","r",stdin);
	scanf("%d %d\n",&v,&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	
	int c[1000];//c[i]: minimum number of coins to present value i
	memset(c,0,sizeof c);
	for(int i=1;i<=v;i++)
		c[i]=MAX;
	c[0]=0;
	
	for(int k=0;k<n;k++){
		for(int i=a[k];i<=v;i++){  //chay tu a[k] nhe'
			c[i]=min(c[i],1+c[i-a[k]]);
		}
	}	
	for(int i=0;i<=v;i++){
		cerr<<c[i]<<" ";
	}
	cerr<<endl;

	printf("%d\n",c[v]);
	return 0;
}
	