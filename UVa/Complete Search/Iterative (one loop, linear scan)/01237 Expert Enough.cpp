#include <bits/stdc++.h>
using namespace std;

struct input{
    string name;
    int minn,maxx;
};

int t;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        int d;
        scanf("%d",&d);
        vector<input> v(d);
        for(int i=0;i<d;i++){
            cin>>v[i].name>>v[i].minn>>v[i].maxx;
        }
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++){
            int cost;
            vector<int> cnt;
            scanf("%d",&cost);
            for(int i=0;i<d;i++){
                if(cost>=v[i].minn && cost<=v[i].maxx) cnt.push_back(i);
            }
            if(cnt.size()!=1) printf("UNDETERMINED\n");
            else cout<<v[cnt[0]].name<<endl;
        }
        if(t) cout<<endl;  //t-- meaning sử dụng rồi giảm nên cuối cùng t=0
    }

    return 0;
}
