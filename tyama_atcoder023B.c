int main(){
	int _r,c,d,i,j,R=0,r;
	scanf("%d%d%d",&_r,&c,&d);
	for(i=0;i<_r;i++)for(j=0;j<c;j++){
		scanf("%d",&r);
		if(i+j<=d&&(i+j)%2==d%2&&R<r)R=r;
	}
	printf("%d\n",R);
	return 0;
}