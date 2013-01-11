/*http://kk.kake.info.waseda.ac.jp/~kakehi/lp12/wl/*/
/*#include <stdio.h>*/
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
	int i,n,s,ma,mi,sum;
	while((n=get_n())!=0){
		ma=0;mi=1000;sum=0;i=0;
		while(i<n){
			s=get_n();
			if(ma<s)ma=s;
			if(mi>s)mi=s;
			sum=sum+s;
			i=i+1;
		}
		put_n((sum-ma-mi)/(n-2));
		fputc('\n',stdout);
	}
	return 0;
}