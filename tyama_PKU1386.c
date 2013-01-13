P[26],A[26],B[26];
int R(a){return P[a]==a?a:(P[a]=R(P[a]));}
char s[999];main(T,k,l,d,x,y){for(scanf("%d",&T);T--;puts(k<26||d>2?"The door cannot be opened.":"Ordering is possible.")){
	for(scanf("%d",&l),k=0;k<26;k++)A[k]=B[k]=0,P[k]=k;
	for(k=0;k<l;k++)scanf("%s",s),A[x=*s-97]++,B[y=s[strlen(s)-1]-97]++,P[R(x)]=R(y);
	for(d=k=0;k<26;k++)if(d+=abs(A[k]-B[k]),(A[k]|B[k])&&R(*s-97)!=R(k))break;
}}