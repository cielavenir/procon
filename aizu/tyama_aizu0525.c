char T[10][10000];
main(Y,X,i,j,r,s,s0,y){
	for(;~scanf("%d%d",&Y,&X)&&Y;printf("%d\n",r)){
		for(j=0;j<Y;j++)for(i=0;i<X;i++)scanf("%hhd",T[j]+i);
		for(r=y=0;y<1<<Y;y++){
			for(s=i=0;i<X;i++){
				for(s0=j=0;j<Y;j++)s0+=(y>>j&1)==T[j][i];
				s+=Y-s0>s0?Y-s0:s0;
			}
			if(r<s)r=s;
		}
	}
exit(0);}
