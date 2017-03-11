X,Y,T[90][90],r;
R(x,y,d){
	if(0<=x&&x<X&&0<=y&&y<Y&&T[y][x]){
		T[y][x]=0;
		R(x-1,y,d+1);
		R(x+1,y,d+1);
		R(x,y-1,d+1);
		R(x,y+1,d+1);
		T[y][x]=1;
	}else if(r<d)r=d;
}
main(i,j){
	for(;~scanf("%d%d",&X,&Y)&&X;printf("%d\n",r)){
		for(j=0;j<Y;j++)for(i=0;i<X;i++)scanf("%d",T[j]+i);
		for(r=j=0;j<Y;j++)for(i=0;i<X;i++)R(i,j,0);
	}
}
