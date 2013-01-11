/*http://kk.kake.info.waseda.ac.jp/~kakehi/lp12/wl/*/
#include <stdio.h>
put_n(int value){
	int v,d[10],i;
	v=value;
	if(value<0)v=-v;
	d[0]=v%10;v=v/10;i=1;
	while(v>0){
		d[i]=v%10;v=v/10;i=i+1;
	}
	if(value<0)fputc('-',stdout);
	while(i>0){
		fputc(d[i-1]+'0',stdout);i=i-1;
	}
}

int get_n(){
	int c,s,n;
	n=0;s=0;
	while((c=fgetc(stdin))!=EOF&&c==' ');
	if(c=='-'||c=='+'){
		if(c=='-')s=1;
		/*while((c=fgetc(stdin))!=EOF&&c==' ');*/
	}
	while('0'<=c&&c<='9'){
		n=n*10+c-'0';c=fgetc(stdin);
	}
	if(s)n=-n;
	return n;
}

int main(){
	int i,n,y,m,d,r;
	n=get_n();
	i=0;
	while(i<n){
		y=get_n()-1;m=get_n()-1;d=get_n();
		r=0;
		if(y%3!=2)r=m/2;
		put_n(196471-y*195-y/3*5-m*20+r-d);
		fputc('\n',stdout);
		i=i+1;
	}
	return 0;
}