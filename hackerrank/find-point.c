main(){
	int t,px,py,qx,qy;
	for(scanf("%d",&t);t--;){
		scanf("%d%d%d%d",&px,&py,&qx,&qy);
		printf("%d %d\n",px+(qx-px)*2,py+(qy-py)*2);
	}
}