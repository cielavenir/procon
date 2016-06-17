#!/usr/bin/pike
int main(int argc, array(string) argv){
	int a,b;
	sscanf(Stdio.stdin.gets(),"%d",a);
	sscanf(Stdio.stdin.gets(),"%d",b);
	Stdio.stdout.write("%d\n",a+b);
}