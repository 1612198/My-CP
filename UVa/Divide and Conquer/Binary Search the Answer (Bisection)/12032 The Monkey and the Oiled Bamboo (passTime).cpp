#include<cstdio>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;
 
int T, n, r[110000];
 
int simul(int k) {
    int d = 0;
    for(int i = 0; i < n; i++) {
        if(r[i] - d < k) {
            d += r[i] - d;
        } else if(r[i] - d == k) {
            d += k;
            k--;
        } else return -1;
    }
    return k;
}
 
int main() {
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    // clock_t start,end;
    // start=clock();
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        scanf("%d", &n);
        for(int j = 0; j < n; j++)
            scanf("%d", &r[j]);
 
        int high = 11000000, low = 0;
        while(high - low > 0) {
            if(simul(high) >= 0) {
                high = low + (high - low) / 2;
            } else {
                low = high;
                high = high + high / 2;
            }
        }
        printf("Case %d: %d\n", i, high + 1);
    }
    // end=clock();
    // cerr<<"Time = "<<((double)(end-start))/CLOCKS_PER_SEC;
    return 0;
}