int x[100000];
int main(){
	int t,n,q,a,b,c,d,r,i;
	for(scanf("%d",&t);t--;){
		scanf("%d%d",&n,&q);
		for(i=0;i<n;i++)scanf("%d",x+i);
		for(i=0;i<q;i++){
			scanf("%d%d%d",&a,&b,&c),b--;
			for(r=0;b<c;b++){
				d=a^x[b];
				if(r<d)r=d;
			}
			printf("%d\n",r);
		}
	}
}