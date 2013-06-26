char s[199],*t="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
a[199];main(i,n){for(;scanf("%d",&n),n;puts("")){
	for(i=0;i<n;i++)scanf("%d",a+i);
	scanf("%s",s);
	for(i=0;i<strlen(s);i++)putchar(t[(strchr(t,s[i])-t-a[i%n]+52)%52]);
}exit(0);}