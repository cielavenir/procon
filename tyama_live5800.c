char s[21];
main(i,t,r,R){for(scanf("%d",&t);t--;puts("")){
	scanf("%d%d%s",&i,&R,s);printf("%d ",i);
	for(i=0;i<strlen(s);i++)for(r=0;r<R;r++)putchar(s[i]);
}}