char m[9][10],s[9];
main(i,j){
	for(i=0;;){
		if(scanf("%s",&s)==-1)return 0;
		for(j=0;j<8;j++)s[j]-=48;
		memcpy(m[i++]+1,s,8);
		if(i==8){
			for(i=0;i<8;i++)for(j=1;j<9;j++)if(m[i][j])goto z;
			printf("%d %d %d\n",i,j,m[0][4]);
			z:if(m[i+1][j]&&m[i][j+1]&&m[i+1][j+1])puts("A");
			else if(m[i][j+1]&&m[i+1][j-1]&&m[i+1][j])puts("G");
			else if(m[i][j+1]&&m[i+1][j+1]&&m[i+1][j+2])puts("E");
			else if(m[i+1][j]&&m[i+1][j-1]&&m[i+2][j-1])puts("D");
			else if(m[i+1][j]&&m[i+1][j+1]&&m[i+2][j+1])puts("F");
			else puts(m[i+1][j]?"B":"C");
			memset(m,0,sizeof(m));i=0;
		}
	}
}