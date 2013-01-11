#define M 100
char m[M][M],s[M][M][M],r[M],*z;
cmp(char *p,char *q){
  int r=0;
  for(;*p=='0';p++);
  for(;*q=='0';q++);
  if(r=strlen(p)-strlen(q))return r;
  return strcmp(p,q);
}
main(w,h,i,j,k,l){
	for(;scanf("%d%d",&w,&h),w;puts(z)){
		memset(m,0xff,sizeof(m));
		memset(s,0,sizeof(s));
		memset(r,0,sizeof(r));
		for(j=1;j<=h;j++)scanf("%s",m[j]+1);
		for(i=1;i<=w+1;i++)for(j=1;j<=h;j++)if(m[j][i]<'0'||'9'<m[j][i])m[j][i]=-1;
		for(k=1;k<M;k++){
			for(j=i=k;i<=w;i++){
				if(m[j][i]==-1)continue;
				if(cmp(s[j][i-1],s[j-1][i])>0)strcpy(s[j][i],s[j][i-1]),s[j][i][strlen(s[j][i])]=m[j][i];
				else strcpy(s[j][i],s[j-1][i]),s[j][i][strlen(s[j][i])]=m[j][i];
				if(cmp(s[j][i],r)>0)strcpy(r,s[j][i]);
			}
			for(j=i=k;j<=h;j++){
				if(m[j][i]==-1)continue;
				if(cmp(s[j][i-1],s[j-1][i])>0)strcpy(s[j][i],s[j][i-1]),s[j][i][strlen(s[j][i])]=m[j][i];
				else strcpy(s[j][i],s[j-1][i]),s[j][i][strlen(s[j][i])]=m[j][i];
				if(cmp(s[j][i],r)>0)strcpy(r,s[j][i]);
			}
		}
		for(z=r;*z=='0';z++);
	}
return 0;}