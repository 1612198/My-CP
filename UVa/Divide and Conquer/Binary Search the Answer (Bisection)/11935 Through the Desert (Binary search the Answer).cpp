//đm nó làm sai rồi, tham khảo thôi :v
#include <cstdio>
#include <cstring>	//strcmp
#include <algorithm>
#include <iostream>
// #include <cfloat>
#include <cmath>
using namespace std;

#define EPS 1e-6
#define maxN 110
#define maxE 50
char cmd[maxE][maxN];
//WHERE IS THE ERROR!!!
double can(double expCap, int nEvents){
	int x = 0, y = 0, leak = 0, fph = 0;
	double rem = expCap;

	char event[maxN];

	//for each event
	for(int i = 0; i < nEvents; ++i){
		const char *s = cmd[i];
		sscanf(s, "%d %s", &y, event);
		rem -= (y - x) * fph / 100.0;
		rem -= (y - x) * leak;
		// res = max(res, cur);
		if (event[0] == 'G' && event[1] == 'o') break;		//goal
		else if (event[0] == 'L') leak++ ;		//leak
		else if (event[0] == 'M') leak = 0;		//mechaninc
		else if (event[0] == 'G') rem = expCap;	//gas station
		else sscanf(s, "%d Fuel consumption %d", &y, &fph);
		if (rem < 0.0) return false;
		x = y;
	}

	return true;	//reached goal
}

void print(){
	for(char *s : cmd)
		printf("%s",s );;
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n = 0;
	int tmpi;
	char tmp[maxN];
	double ans = 0.0;

	while (fgets(cmd[n], maxN, stdin)){
		if (!(strcmp(cmd[n], "0 Fuel consumption 0"))) break;		
		do{
			sscanf(cmd[n], "%d %s", &tmpi, tmp);
			if (tmp[0] == 'G' && tmp[1] == 'o'){
				// print();
				double lo = 0.0, hi = 1e4, mid = 0;
				for (int i = 0; i < 50; ++i){
					mid = (lo + hi) / 2;
					// double cap = can(mid, n);
					// if (fabs(cap) < EPS) {
					// 	printf("%.3lf\n", mid);
					// 	break;
					// }
					// else if (cap > 0.0) hi = mid;
					// else lo = mid;
					if (can (mid, n)){
						ans = mid; //ans=mid bỏ này hay bỏ dưới đều được
						hi = mid;
					}
					else lo = mid;
				}
				break;
			} 
			n++;
		}while (fgets(cmd[n], maxN, stdin));
		
		cout << n << endl;
		printf("%.3lf\n", ans );
		n = 0;
	}
	return 0;
}