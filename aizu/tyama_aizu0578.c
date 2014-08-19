char s[99],t[101],*T;
r;main(n,i,j){for(scanf("%d%s",&n,s);n--;){
	for(scanf("%s",t),T=t-1;;){
		if(!(T=strchr(T+1,s[0])))break;
		for(i=1;T[i];i++)
			if(T[i]==s[1]){
				for(j=2;j<strlen(s);j++)if(i*j>=strlen(T)||T[i*j]!=s[j])break;
				if(j==strlen(s)){r++;goto next;}
			}
	}
	next:;
}printf("%d\n",r);exit(0);}