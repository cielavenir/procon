#!/usr/bin/pike
void judge(int n){
	int ma=0,mi=1000,s=0;
	for(int i=0;i<n;i++){
		int x;
		sscanf(Stdio.stdin.gets(),"%d",x);
		if(x<mi)mi=x;
		if(x>ma)ma=x;
		s+=x;
	}
	Stdio.stdout.write(sprintf("%d\n",(s-ma-mi)/(n-2)));
}

int main(int argc, array(string) argv){
	while(1){
		int n;
		sscanf(Stdio.stdin.gets(),"%d",n);
		if(n==0)break;
		judge(n);
	}
}