#define X r+=(m*p+n*q)%(m*m+n*n)==0&&(m*q-n*p)%(m*m+n*n)==0
#define Z if(X,n=-n)X,n=-n
main(T,p,q,m,n,r){for(scanf("%d",&T);T--;puts(r==8?"P":"C"))for(scanf("%d%d",&p,&q),r=m=0;m*m<=p*p+q*q;m++)for(n=m?0:1;m*m+n*n<=p*p+q*q;n++){Z;if(m=-m){Z;m=-m;}}exit(0);}