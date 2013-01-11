char s[9999],t[999];
main(i,j,m,r){
	for(scanf("%s",&s),i=j=0;i<strlen(s);)
		if(s[i]=='e')t[j++]='e',i+=3;
		else t[j++]='c',i+=7;
	for(m=i=0;i<strlen(t);i=j){
		for(j=i+1;j<strlen(t);j++)if(t[j]==t[j-1])break;
		if(m<j-i)m=j-i,r=t[j-1];
	}
	puts(r=='c'?"chicken":"egg");exit(0);
}