#include <stdio.h>
int r,x,m=1;
int main(int c,char **a){
	freopen(a[1],"rb",stdin);
	do{
		c=getchar();
		c==' '||c=='\n'||!~c ? r+=x*m,x=0,c!=' '&&!~m&&puts(r<=0?"True":"False")&&(m=1,r=0)
		: c=='|' ? m=-1
		: (x=~m?x*16+(c>'9'?c-'a'+10:c-'0'):x*2+c%2);
	}while(~c);
	return 0;
}