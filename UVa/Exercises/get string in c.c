#include <bits/stdc++.h>

int main()
{
	char s[100];
	scanf("%s",s); //read string đến khi gặp khoảng trắng, tự động thêm '\0'
	printf("%s\n",s); 
	fgets(s,100,stdin); //fgets (char* ,int size, FILE* stream); đọc size kí tự, tự động thêm '\0'
	//ko nên sử dụng gets(s); vì nó sẽ tiếp store characters past the end of the buffer vì nó ko đọc kí tự xuống dòng ở lượt nó, it is dangerous to use
	scanf("%[^\n]\n",s); //[^\n] đọc đến kí tự \n và không lưu \n (sau) vào s
	return 0;
}