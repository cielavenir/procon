main(){
	int H,W,i,j;
	scanf("%d%d",&H,&W);getchar();
	for(i=0;i<H;i++){
		int p=-1;
		for(j=0;j<W;j++){
			int c=getchar();
			if(c=='c')p=0;
			else if(p>=0)p++;
			printf(j<W-1?"%d ":"%d\n",p);
		}
		getchar();
	}
	return 0;
}