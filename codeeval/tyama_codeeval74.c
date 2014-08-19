a[]={5,3,1},n;
int rec2c(int n){
	if(n==0)return 0;
	int i=0,j;
	for(;i<3;i++)if(n>=a[i]){
		for(j=0;j<3;j++)if((n-a[i])%a[j]==0)break;
		if(j<3){
			int ret=rec2c(n-a[i]);
			if(ret>=0)return ret+1;
		}
	}
	return -1;
}
main(){for(;~scanf("%d",&n);)printf("%d\n",rec2c(n));}