int D[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
struct{int x,y;}m[200];
main(i,N,mx,my,Mx,My,n,d){
	for(;scanf("%d",&N),N;printf("%d %d\n",Mx-mx+1,My-my+1)){
		m[0].x=m[0].y=Mx=mx=My=my=0;
		for(i=1;i<N;i++){
			scanf("%d%d",&n,&d);
			m[i].x=m[n].x+D[d][0],m[i].y=m[n].y+D[d][1];
			if(Mx<m[i].x)Mx=m[i].x;
			if(mx>m[i].x)mx=m[i].x;
			if(My<m[i].y)My=m[i].y;
			if(my>m[i].y)my=m[i].y;
		}
	}
	exit(0);
}