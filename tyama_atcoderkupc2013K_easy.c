char e[9],s[999999];
main(N,i){
	scanf("%s%d%s",e,&N,s);
	if(*e=='e')
		for(i=0;i<N;i++)printf(s[i]=='0'?"BC":"BE");
	else
		for(i=0;i*2<N;i++)printf(s[i*2+1]=='C'?"0":"1");
	puts("");
	exit(0);
}