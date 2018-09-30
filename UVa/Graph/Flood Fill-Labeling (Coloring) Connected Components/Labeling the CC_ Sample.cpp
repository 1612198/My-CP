int dr[]={1,1,0,-1,-1,-1,0,1};  //trick to explore an implicit 2D grid
int dc[]={0,1,1,1,0,-1,-1,-1};  //S,SE,E,NE,N,NW,W,SW (8 hướng địa lý)

//cần đếm số cell chứa c1 (connected component nhé) trong 2D area
//đếm số cell trong 1 CC.
int floodfill(int r,int c,char c1,char c2){  //return the size of CC
	if(r<0 ||r>=R ||c<0 || c>=C) return 0;   //outside grid
	if(grid[r][c]!=c1) return 0; //does not have color c1
	int ans=1; //add 1 to ans because vertex (r,c) has c1 as its color
	grid[r][c]=c2; //recolor to avoid count again, đếm rồi thì fill thôi :v
	for(int d=0;d<8;d++)
		ans+=floodfill(r+dr[d],c+dc[d],c1,c2);  //type dfs search
	return ans; 
}