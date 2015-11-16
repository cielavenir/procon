int lcs[199][199];char s[199],*t;

int f(char *s,char *t,int a,int b){
	memset(lcs,0,sizeof(lcs));
	int m,i,j;
	for(m=0,i=1;i<=a;i++){
		for(j=1;j<=b;j++){
			lcs[i][j]=s[i-1]==t[j-1]?lcs[i-1][j-1]+1:lcs[i-1][j-1];
			if(lcs[i][j]<lcs[i-1][j])lcs[i][j]=lcs[i-1][j];
			if(lcs[i][j]<lcs[i][j-1])lcs[i][j]=lcs[i][j-1];
			if(m<lcs[i][j])m=lcs[i][j];
		}
	}
	return m;
}

int main(){
	int N,R=0,r,i=0;
	scanf("%d%s",&N,s);
	for(;i<N;i++){
		r=f(s,s+i,i,N-i);
		if(R<r)R=r;
	}
	printf("%d\n",N-R*2);
	return 0;
}