P[26],A[26],B[26];
int R(a){return P[a]==a?a:(P[a]=R(P[a]));}
char s[99];main(k,l,x,y){for(;scanf("%d",&l),l;puts(k<26?"NG":"OK")){
	for(k=0;k<26;k++)A[k]=B[k]=0,P[k]=k;
	for(k=0;k<l;k++)scanf("%s",s),A[x=*s-97]++,B[y=s[strlen(s)-1]-97]++,P[R(x)]=R(y);
	for(k=0;k<26;k++)if(A[k]-B[k]||(A[k]&&R(*s-97)!=R(k)))break;
}exit(0);}