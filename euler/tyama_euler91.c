#define M 51
main(m,j,k,x1,x2,x3,y1,y2,y3){
	for(m=x1=y1=0,j=1;j<M*M-1;j++)for(k=j+1;k<M*M;k++){
		x2=j%M,y2=j/M,x3=k%M,y3=k/M;
		m+=((x2-x1)*(x3-x1)+(y2-y1)*(y3-y1))*((x1-x2)*(x3-x2)+(y1-y2)*(y3-y2))*((x1-x3)*(x2-x3)+(y1-y3)*(y2-y3))==0;
	}
	printf("%d\n",m);
}