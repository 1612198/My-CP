#include <stdio.h>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-6; //EPS: epsilon
#define maxN 110
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char s[maxN];
	while(gets(s)){
		if(strcmp(s,"0 Fuel consumption 0")==0) break;
		int x=0, y=0, leak=0, fph=0; //fuel per hundred
		double res=0.0, cur=0.0; //current consumption
		char event[maxN];  //%s format of char[]
		do{
			sscanf(s,"%d %s",&y,event); //next event
			cur+=(y-x)*fph/100.0;
			cur+=(y-x)*leak;
			res=max(res,cur);

			if(event[0]=='G'&&event[1]=='o') break; //Goal
			else if(event[0]=='L') leak++;   //leak
			else if(event[0]=='M') leak=0; //mechanic
			else if(event[0]=='G') cur=0.0;  //gas station
			else sscanf(s,"%d Fuel consumption %d",&y,&fph);
			x=y;
		}while(gets(s));
		printf("%.3lf\n",res);
	}
	

	return 0;
}