int main(){
	int a,b,c,d,e,r=0;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	if(a<0)r-=a*c,a=0;
	if(a==0)r+=d+e,a=1;
	printf("%d\n",r+(b-a)*e);
	return 0;
}
