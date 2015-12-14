a[101];
int main(){
	int n,t,x,i;
	scanf("%d",&n);
	for(i=0;i<3;i++)for(scanf("%d",&t);t--;a[x]|=(1<<i))scanf("%d",&x);
	for(x=i=0;++i<=n;)x+=(a[i]&5)==4||(a[i]&6)==6;
	printf("%d\n",x);
	return 0;
}