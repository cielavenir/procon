#!/usr/bin/pike
int main(int argc, array(string) argv){
	int n,k,m,r;
	for(;;){
		sscanf(Stdio.stdin.gets(),"%d%d%d",n,k,m);
		if(!n)break;
		for(int i=0;++i<n;r%=i)r+=k;
		Stdio.stdout.write("%d\n",(r+m)%n+1);
	}
}