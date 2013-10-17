char s[41],a[38];
main(i,t){for(scanf("%d",&t);t--;puts("")){
	scanf("%d%s",&i,s);printf("%d",i);memset(a,0,sizeof(a));
	for(i=0;i<38;i++)a[(s[i]=='H'?4:0)|(s[i+1]=='H'?2:0)|(s[i+2]=='H'?1:0)]++;
	for(i=0;i<8;i++)printf(" %d",a[i]);
}}