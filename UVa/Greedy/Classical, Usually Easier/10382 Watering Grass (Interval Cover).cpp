//Tham lam theo kiểu phải nhất mà vẫn connect với cái trước
// lấy cái điểm phải nhất làm gốc để chạy (cur)
// cái internal nào mà left<cur && right>cur, chọn, vì sort theo chiều
//gỉam của right rồi nên ta luôn gặp được phải nhất đầu tiên (this is greedy)

#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	double lon,wide;
	while(~scanf("%d%lf%lf",&n,&lon,&wide)){
		vector<pair<double,double>> rl;
		int pos,rad;
		for(int i=0;i<n;i++){
			scanf("%d%d",&pos,&rad);
			double dx=sqrt(max(0.0,rad*rad*1.0-wide*wide/4.0));
			rl.push_back(make_pair(dx+pos,pos-dx));
		}
		//rl.first: Right rl.second: left
		sort(rl.rbegin(),rl.rend());
		double cur=0; //most right
		int cnt=0;
		while(cur<lon){
			int i;
			for(i=0;i<n;i++){
				if(rl[i].second<=cur&&rl[i].first>cur){
					cur=rl[i].first;
					cnt++;
					break;
				}
			}
			if(i==n) break;  //tất cả mép trái đều >0 nên ko thể phủ được, break sớm bớt đau khổ
		}
		if(cur<lon) printf("-1\n");
		else printf("%d\n",cnt);
	}
	return 0;
}
