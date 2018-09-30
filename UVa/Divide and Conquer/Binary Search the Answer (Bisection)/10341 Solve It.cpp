#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-7

int p,q,r,s,t,u;

double f(double x){
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

double bisection(){
	double lo=0, hi=1;
	while(abs(hi-lo)>EPS){
		double mid=(hi+lo)/2.0;
		if(f(lo)*f(mid)<=0){  //đoạn [lo;mid] chứa nghiệm
			hi=mid;
		}else{  //đoạn này ko có nghiệm, nhích lo qua để mid sang phải
			lo=mid; 
		}
	}
	return (lo+hi)/2;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)!=EOF){
		if(f(0)*f(1)>0) {
			printf("No solution\n");
		}else{
			printf("%.4lf\n",bisection());
		}
	}

	return 0;
}