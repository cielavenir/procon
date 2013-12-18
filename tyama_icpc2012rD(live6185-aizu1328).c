double V[16],s,p;
int D,i,j,k,l;
main(){for(;scanf("%d",&D),D;){D+=3;
	for(i=0;i<D;++i)scanf("%lf",V+i);
	for(i=0;i<D;++i){
		for(j=0;j<D;++j)if(j!=i){
			for(s=k=0;k<D;++k)if(k!=i&&k!=j){
				p=V[k];
				for(l=0;l<D;++l)if(l!=k&&l!=i&&l!=j)p=p*(j-l)/(k-l);
				s+=p;
			}
			if(fabs(s-V[j])>0.1)break;
		}
		if(j==D){
			printf("%d\n",i);
			break;
		}
	}
}}