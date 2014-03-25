a[50][50],b[50][50],c[50][50];
main(){
	int H,W,h,w,i,j,k,R=-99999,r;
	scanf("%d%d",&H,&W);
	for(i=0;i<H;i++)for(j=0;j<W;j++)scanf("%d",a[i]+j);
	for(i=0;i<H;i++)for(j=0;j<W;j++)scanf("%d",b[i]+j);
	scanf("%d%d",&h,&w);
	for(i=0;i<h;i++)for(j=0;j<w;j++)scanf("%d",c[i]+j);
	for(i=0;i<=H-h;i++)for(j=0;j<=W-w;j++){
		for(r=k=0;k<h*w;k++){
			r+=a[i+k/w][j+k%w];
			if(b[i+k/w][j+k%w]!=c[k/w][k%w])break;
		}
		if(k==h*w&&R<r)R=r;
	}
	printf(R==-99999?"NA\n":"%d\n",R);
exit(0);}