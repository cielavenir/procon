main(){
	int M,j,k,x1=0,x2,x3,y1=0,y2,y3;
	long long m=0;
	scanf("%d",&M),M++;
	for(j=1;j<M*M-1;j++)for(k=j+1;k<M*M;k++){
		x2=j%M,y2=j/M,x3=k%M,y3=k/M;
		m+=((x2-x1)*(x3-x1)+(y2-y1)*(y3-y1))*((x1-x2)*(x3-x2)+(y1-y2)*(y3-y2))*((x1-x3)*(x2-x3)+(y1-y3)*(y2-y3))==0;
	}
	printf("%d\n",m);
}
//50