#include <bits/stdc++.h>
using namespace std;


int n,m,s;
string cmd;
vector<string> a;
int cnt=0;
class robott{
    int x,y; //x: rows, y: columns
    char dir; //direction
public:
    robott(){}
   
    robott(int x,int y,char dir){
        this->x=x;
        this->y=y;
        this->dir=dir;
    }
    void xoayPhai(){
        switch(dir){
            case 'N': dir='L';break;
            case 'L': dir='S';break;
            case 'S': dir='O';break;
            case 'O': dir='N';break;
        }
    }
    void xoayTrai(){
        switch(dir){
            case 'N': dir='O';break;
            case 'L': dir='N';break;
            case 'S': dir='L';break;
            case 'O': dir='S';break;
        }
    }
    void go(char c){

        switch(c){
            case 'D': this->xoayPhai(); break;
            case 'E': this->xoayTrai(); break;
            case 'F': {
                int xx=x,yy=y;
                switch (dir){
                    case 'N': xx=x-1; break;
                    case 'S': xx=x+1; break;
                    case 'L': yy=y+1; break;
                    case 'O': yy=y-1; break; 
                }
                xx=min(max(0,xx),n-1);
                yy=min(max(0,yy),m-1);
                if(a[xx][yy]=='#') break;
                if(a[xx][yy]=='*') {
                    cnt++;
                    a[xx][yy]='.';
                }
                x=xx;y=yy;  //chú ý cái vị trí ban đầu thì thay = '.', nghĩa là còn lại đi bình thường

                break;
            }
        }
    }
};

int main()
{
    // freopen("11902 in.txt","r",stdin);
    // freopen("11902 out.txt","w",stdout);

    while(scanf("%d%d%d",&n,&m,&s),n||m||s){
        a.resize(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cin>>cmd;

        robott r;
        for(int i=0;i<n;i++)
            for(int j=0;j<a[i].size();j++){
                if(a[i][j]=='O'||a[i][j]=='N'||a[i][j]=='S'||a[i][j]=='L') {
                    r=robott(i,j,a[i][j]);
                    break;
                }
            }

        for(int i=0;i<s;i++){
            r.go(cmd[i]);
        }
        printf("%d\n",cnt);
        cnt=0;
    }



    return 0;
}