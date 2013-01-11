m[8][8];main(i,j){
	for(i=0;i<8;getchar(),i++)for(j=0;j<8;j++)m[i][j]=getchar();
	for(puts("90"),i=0;i<8;putchar('\n'),i++)for(j=7;j>=0;j--)putchar(m[j][i]);
	for(puts("180"),i=7;i>=0;putchar('\n'),i--)for(j=7;j>=0;j--)putchar(m[i][j]);
	for(puts("270"),i=7;i>=0;putchar('\n'),i--)for(j=0;j<8;j++)putchar(m[j][i]);
	exit(0);
}