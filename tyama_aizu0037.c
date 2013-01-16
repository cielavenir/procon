X[]={1,0,-1,0},Y[]={0,1,0,-1},s[11][11];char *D="RDLU";
main(x,y,i,j,z){
	x=y=5;
	for(j=0;j<2*y;j++)for(i=0;i<2*x;i++)s[i][j]=0;
	for(j=1;j<2*y;getchar(),j++)for(i=(j&1)?2:1;i<2*x;i+=2)s[i][j]=getchar()-'0';
	putchar('R');
	for(z=0,x=3,y=1;x!=1||y!=1;){
		z=(z+3)%4;
		for(;!s[x+X[z]][y+Y[z]];z=(z+1)%4);
		x+=X[z]*2,y+=Y[z]*2;
		putchar(D[z]);
	}
	puts("");exit(0);
}