char W[9],V[9];Z[8],S,N,T,P,M;main(i,j,k,l,r,d){for(;scanf("%d%d%d%s%s%d%d",&S,&N,&T,W,V,&P,&M),S;printf("%.10f\n",1-pow(1-1.0/P,N*r))){
	memset(Z,0,sizeof(Z));
	l=*W=='A'?2:1;
	d=24*60*(*W=='A'?1:7);
	if(*V=='A')for(i=0;i<l;i++)Z[i*4]=Z[i*4+1]=Z[i*4+2]=Z[i*4+3]=1;
	if(*V=='D')for(i=0;i<l;i++)Z[i*4+1]=Z[i*4+2]=1;
	if(*V=='N')for(i=0;i<l;i++)Z[i*4]=Z[i*4+3]=1;
	for(r=j=0;j<24*60;r=r>l?r:l,j++)for(k=j,l=i=0;i<M;k=(k+T)%d,i++)if(k<24*60)l+=Z[(k+S)%(48*60)/360]&Z[k/360];
}exit(0);}