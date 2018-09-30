//read input with blank line
cin don't get anything after integer. That means cin's input buffer
still contains the rest of the line that the number was on. So, you
need to skip that line, and the next blank line.You could do that
by just using getline twices
cin>>integer;
getline(cin,blank);
getline(cin,blank);
or using: scanf("%d\n\n",&integer);

while(getline(cin,line)&&!line.empty()){
	//do stuff
}
