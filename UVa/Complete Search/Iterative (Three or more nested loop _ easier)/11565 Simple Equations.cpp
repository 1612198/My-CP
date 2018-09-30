#include <bits/stdc++.h>
using namespace std;
int N;
int A,B,C;
void sortxyz(int& x,int& y, int&z){
    vector<int> tmp;
    tmp.push_back(x);
    tmp.push_back(y);
    tmp.push_back(z);
    sort(tmp.begin(),tmp.end());
    x=tmp[0]; y=tmp[1];z=tmp[2];
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&N);
    while(N--){
        scanf("%d %d %d",&A,&B,&C);
        bool coNghiem=false;
        for(int x=-22;x<=22 && !coNghiem;x++){ //đưa coNghiem lên đây hay nè :v
            for(int y=-100;y<=100 && !coNghiem;y++){
                int z=A-x-y; //chỗ này tao còn làm tốt hơn Steven Halim :v
                if(x*y*z==B && x*x+y*y+z*z==C&& x!=y&&y!=z&&z!=x) {
                    sortxyz(x,y,z);
                    printf("%d %d %d\n",x,y,z);
                    coNghiem=true;
                    break;
                }
                //if(coNghiem) break;
            }
            //if(coNghiem) break;
        }
        if(!coNghiem) printf("No solution.\n");
    }

    return 0;
}
