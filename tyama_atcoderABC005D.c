int m[51][51],d[2501];
main(){
	int N,X,Y,x,y,p,s;
	//perform summation(koj0019 KOG)
	scanf("%d",&N);
	for(y=1;y<=N;y++)for(x=1;x<=N;x++)scanf("%d",m[y]+x);
	for(y=1;y<=N;y++)for(x=1;x<=N;x++)m[y][x]+=m[y-1][x];
	for(y=1;y<=N;y++)for(x=1;x<=N;x++)m[y][x]+=m[y][x-1];
	//enumerate rectangles
	for(y=1;y<=N;y++)for(x=1;x<=N;x++)for(Y=y;Y<=N;Y++)for(X=x;X<=N;X++){
		s=(Y-y+1)*(X-x+1);
		p=m[Y][X]-m[y-1][X]-m[Y][x-1]+m[y-1][x-1];
		if(d[s]<p)d[s]=p;
	}
	//check lower value
	for(x=1;x<=N*N;x++)if(d[x]<d[x-1])d[x]=d[x-1];
	//output
	for(scanf("%d",&N);N--;)scanf("%d",&x),printf("%d\n",d[x]);
	exit(0);
}