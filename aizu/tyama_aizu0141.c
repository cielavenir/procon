m[100][100];D(x,y,n){if(n<4){
	m[x][y]=1;
	if(n>1)m[x][y-1]=1;
	if(n==2)m[x+1][y-1]=1;
	if(n>2)m[x][y-2]=1,m[x+1][y-2]=1,m[x+2][y-2]=1,m[x+2][y-1]=1,m[x+2][y]=1;
}else{
	int i=0,j=0;
	for(;j<n;j++)m[x+i][y-j]=1;j--;
	for(;i<n;i++)m[x+i][y-j]=1;i--;
	for(;j>=0;j--)m[x+i][y-j]=1;j++;
	for(;i>=2;i--)m[x+i][y-j]=1;j++;
	if(n-4)m[x+2][y-1]=1,D(x+2,y-2,n-4);
}}
main(d,n,i,j){for(scanf("%d",&d);d;d--){
	memset(m,0,sizeof(m));scanf("%d",&n);D(0,n-1,n);
	for(i=0;i<n;puts(""),i++)for(j=0;j<n;j++)putchar(m[j][i]?'#':' ');
	if(d>1)puts("");
}exit(0);}