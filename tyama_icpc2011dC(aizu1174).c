h,w,c,S,max,C,N,r;
int *_M;
D(x,y){
	_M[x+(w+2)*y]=N;
	if(_M[x-1+(w+2)*y]==C)r++,D(x-1,y);
	if(_M[x+1+(w+2)*y]==C)r++,D(x+1,y);
	if(_M[x+(w+2)*(y-1)]==C)r++,D(x,y-1);
	if(_M[x+(w+2)*(y+1)]==C)r++,D(x,y+1);
}
E(int d,int *M){if(d<4||M[1+w+2]!=c){
	int *m=malloc(S);
	if(d==4){
		memcpy(_M=m,M,S);
		C=m[1+w+2],N=c;D(1,1);
		C=c,N=-1,r=1;D(1,1);
		if(max<r)max=r;
	}else{
		int i=1;
		for(;i<7;i++)if(M[1+w+2]!=i){
			memcpy(_M=m,M,S);
			C=m[1+w+2],N=i;D(1,1);
			E(d+1,m);
		}
	}
	free(m);
}}
a[100];
main(i,j){for(;scanf("%d%d%d",&h,&w,&c),c;printf("%d\n",max)){
	memset(a,0,S=4*(w+2)*(h+2));
	for(j=1;j<h+1;j++)for(i=1;i<w+1;i++)scanf("%d",a+i+(w+2)*j);
	E(max=0,a);
}}