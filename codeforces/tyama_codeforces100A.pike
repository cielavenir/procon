#!/usr/bin/pike
int main(int argc, array(string) argv){
	int n,m,k;
	sscanf(Stdio.stdin.gets(),"%d%d%d",n,k,m);
	n=(n+m-1)/m;
	Stdio.stdout.write(n*n<=k ? "YES\n" : "NO\n");
}