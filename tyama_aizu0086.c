t[101];main(a,b,i){for(t[1]=t[2]=1;;){
if(scanf("%d%d",&a,&b)<2)exit(0);
if(!a){
	for(i=1;i<=101;i++)if(t[i]&1)break;
	puts(i>101?"OK":"NG");memset(t,0,sizeof(t)),t[1]=t[2]=1;
}
t[a]++,t[b]++;
}}