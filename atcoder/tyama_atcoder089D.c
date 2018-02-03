m[9999][9999];
main(){
	int n,k,x,y,i,j;
	char c[2];
	scanf("%d%d",&n,&k);
	for(;n--;){
		scanf("%d%d%s",&x,&y,c);
		if(*c=='W')y+=k;
		x%=2*k;
		y%=2*k;
		for(i=0;i<4;i++){
			for(j=i%2;j<4;j+=2){
				m[x+i*k][y+j*k]++;
				m[x+i*k+k][y+j*k]--;
				m[x+i*k][y+j*k+k]--;
				m[x+i*k+k][y+j*k+k]++;
			}
		}
	}
	for(i=0;i<6*k;i++)for(j=1;j<6*k;j++)m[i][j]+=m[i][j-1];
	for(i=1;i<6*k;i++)for(j=0;j<6*k;j++)m[i][j]+=m[i-1][j];
	for(y=i=0;i<6*k;i++)for(j=0;j<6*k;j++)y=(x=m[i][j])>y?x:y;
	printf("%d\n",y);
}
