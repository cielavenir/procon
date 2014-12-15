void bt(int x){
	int q=(x+1)/3;
	int r=(x+1)%3;
	if(q)bt(q);
	putchar("-0+"[r]);
}
main(){
	int x;
	scanf("%d",&x);
	bt(x);puts("");
}