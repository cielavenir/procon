o(f,s,e,l){if(s==e)printf("%s%d%s",f?" ":"",s,l?"\n":"");else printf("%s%d-%d%s",f?" ":"",s,e,l?"\n":"");}
main(n,s,e,x,f){
	for(;scanf("%d",&n),n;o(f,s,e,1))
		for(scanf("%d",&s),e=s,f=0;--n;){
			scanf("%d",&x);
			if(x-e==1){e++;continue;}
			o(f,s,e,0);
			s=e=x,f=1;
		}
	return 0;
}