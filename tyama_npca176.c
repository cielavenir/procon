int main(){
	int n,r=0;
	for(scanf("%d",&n);n>1;r++)n=(n&1)?3*n+1:(n/2);
	printf("%d\n",r);
	return 0;
}