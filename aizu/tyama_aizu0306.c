int bt(int x){
	int q=(x+1)/3;
	int r=(x+1)%3;
	int d=0;
	if(q)d+=bt(q);
	putchar("-0+"[r]);
	return d+1;
}
int main(){
	int x;
	scanf("%d",&x);
	int d=bt(x);
	puts("");
	//printf("%d\n",d);
	return 0;
}