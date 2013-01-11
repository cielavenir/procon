#!/usr/bin/vala
static void main(){
	int n,y,m,d;
	stdin.scanf("%d",out n);
	for(int i=0;i<n;i++){
		stdin.scanf("%d%d%d",out y,out m,out d);
		y--;m--;
		stdout.printf("%d\n",196471-y*195-y/3*5-m*20+(y%3!=2?m/2:0)-d);
	}
}