#define M 60000
m[M+1];
main(i,d){
	m[0]=1;
	for(d=1;d<=M;d++){
		for(i=d;i<=M;i++){
			m[i]=(m[i]+m[i-d])%1000000;
		}
	}
	for(i=0;i<=M;i++)if(m[i]==0){printf("%d\n",i);break;}
	exit(0);
}