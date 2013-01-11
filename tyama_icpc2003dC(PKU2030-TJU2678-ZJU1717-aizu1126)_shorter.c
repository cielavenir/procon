#define M 100
char m[M][M],s[M][M][M],r[M],*z;
cmp(char *p,char *q){
	for(;*p=='0';p++);for(;*q=='0';q++);
	return (z=strlen(p)-strlen(q))?z:strcmp(p,q);
}
main(w,h,i,j,k,l){
	for(;scanf("%d%d",&w,&h),w;puts(z)){
		for(memset(s,0,sizeof(s)),*r=0,j=1;j<=h;j++)scanf("%s",m[j]+1);
		for(i=1;i<=w;i++)for(j=1;j<=h;j++){
			if(!isdigit(m[j][i]))continue;
			if(cmp(s[j][i-1],s[j-1][i])>0)strcpy(s[j][i],s[j][i-1]),s[j][i][strlen(s[j][i])]=m[j][i];
			else strcpy(s[j][i],s[j-1][i]),s[j][i][strlen(s[j][i])]=m[j][i];
			if(cmp(s[j][i],r)>0)strcpy(r,s[j][i]);
		}
		for(z=r;*z=='0';z++);
	}
return 0;}