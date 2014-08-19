char s[101],p[101];i;main(j){for(scanf("%s%s",s,p);i<strlen(s);i++){
	for(j=0;j<strlen(p);j++)if(s[(i+j)%strlen(s)]!=p[j])break;
	if(j==strlen(p))puts("Yes"),exit(0);
}puts("No"),exit(0);}