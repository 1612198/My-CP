#include <bits/stdc++.h>
using namespace std;


struct constraints{  //sài mảng 2 chiều cũng được, int constraints[20][3]
    int a,b,c;
};

int convertIt(vector<int> &m,vector<int>::iterator it){
    for(int i=0;i<m.size();i++){
        if(m.begin()+i==it) return i;
    }
}

int n,m;


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d",&n,&m),n||m){
        vector<int> mem(n);//chỗ này có thể code cứng: int mem[]={0,1,2,3,4,5,6,7};
        vector<constraints> v;
        int cnt=0;

        for(int i=0;i<n;i++)
            mem[i]=i;
        constraints cons;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&cons.a,&cons.b,&cons.c);
            v.push_back(cons);
        }
        do{
            int j=0;
            for(;j<m;j++){
                vector<int>::iterator it=find(mem.begin(),mem.end(),v[j].a);
                int posa=convertIt(mem,it);
                it=find(mem.begin(),mem.end(),v[j].b);
                int posb=convertIt(mem,it);
                if(v[j].c>0 &&
                   abs(posa - posb)>v[j].c
                   ) break;
                if(v[j].c<0 &&
                   abs(posa - posb)<(-v[j].c)
                   ) break;
            }
            if(j==m) cnt++;
        }while(next_permutation(mem.begin(),mem.end())); //tới đây next_permutation(mem,mem+n)

        printf("%d\n",cnt);
    }

    return 0;
}
