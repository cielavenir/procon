#define M 101
char s[M][M];
int m[M][M],h,w;

dfs(j,i,c){
	if(m[j][i]!=c)return;
	m[j][i]=-1;
	if(0<j)dfs(j-1,i,c);
	if(0<i)dfs(j,i-1,c);
	if(j<h-1)dfs(j+1,i,c);
	if(i<w-1)dfs(j,i+1,c);
}

main(i,j,cur,count){
	memset(m,0xff,sizeof(m));
	for(scanf("%d%d",&h,&w),j=0;j<h;j++)scanf("%s",s[j]);
	for(i=0;i<w;i++){
		cur=s[0][i],count=1;
		for(j=1;j<h;j++){
			if(cur==s[j][i])count++;
			else{
				if(count>=3)for(;count;count--)m[j-count][i]=cur-'0';
				count=1;
				cur=s[j][i];
			}
		}
		if(count>=3)for(;count;count--)m[j-count][i]=cur-'0';
	}
	for(j=0;j<h;j++){
		cur=s[j][0],count=1;
		for(i=1;i<w;i++){
			if(cur==s[j][i])count++;
			else{
				if(count>=3)for(;count;count--)m[j][i-count]=cur-'0';
				count=1;
				cur=s[j][i];
			}
		}
		if(count>=3)for(;count;count--)m[j][i-count]=cur-'0';
	}
	//for(j=0;j<h;puts(""),j++)for(i=0;i<w;i++)printf("%d\t",m[j][i]);
	for(count=j=0;j<h;j++)for(i=0;i<w;i++)if(~m[j][i])dfs(j,i,m[j][i]),count++;
	printf("%d\n",count);
	exit(0);
}