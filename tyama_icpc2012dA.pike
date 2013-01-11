#!/usr/bin/pike
int main(int argc, array(string) argv){
	int n,y,m,d;
	sscanf(Stdio.stdin.gets(),"%d",n);
	for(int i=0;i<n;i++){
		sscanf(Stdio.stdin.gets(),"%d%d%d",y,m,d);
		Stdio.stdout.write("%d\n",196471-(--y)*195-y/3*5-(--m)*20+(y%3-2?m/2:0)-d);
	}
}