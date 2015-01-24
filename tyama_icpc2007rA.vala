#!/usr/bin/vala
static void main(){
	int r,i,n,k,m;
	for(;;){
		stdin.scanf("%d%d%d",out n,out k,out m);
		if(n==0)break;
		for(r=i=0;++i<n;r%=i)r+=k;
		stdout.printf("%d\n",(r+m)%n+1);
	}
}