#include <bits/stdc++.h>
using namespace std;

int n;
int a,b,row[8];
int lineCounter;
bool place (int c,int r){ //column, row
    for(int prev=0;prev<c;prev++){
        if(row[prev]==r || abs(r-row[prev])==abs(c-prev)) return false;
    }
    return true;
}

void backtrack(int c){ //c:column need to set row corresponding
    if(c==8 && row[b]==a){ //completely a answer
        printf("%2d      %d", ++lineCounter, row[0] + 1);
		for (int j = 1; j < 8; j++) printf(" %d", row[j] + 1);
		printf("\n");
    }
    else{
        for(int r=0;r<8;r++){
            //if(row[b]!=a) continue;
            if(place(c,r)){
                row[c]=r;
                backtrack(c+1);
            }
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&a,&b);
        a--;b--; //switch to 0-based indexing
        memset(row,0,sizeof(row));
        lineCounter=0;
   		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack(0);
        if(n) printf("\n");

    }

    return 0;
}
