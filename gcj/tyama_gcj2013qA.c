char m[6][6];
main(t,T,i,j,c,w,z){
	for(scanf("%d",&T);t<=T;t++){
		for(i=1;i<=4;i++)scanf("%s",m[i]+1);
		for(z=0,i=1;i<=4;i++)for(j=1;j<=4;j++)z+=m[i][j]=='.';
		for(w=0,i=1;i<=4;i++){
			c=m[i][1]=='T'?m[i][2]:m[i][1];
			j=2;if(c!='.')for(;j<=4;j++)if(m[i][j]!='T'&&m[i][j]!=c)break;
			if(j>4)w|=(c=='X'?1:2);
			c=m[1][i]=='T'?m[2][i]:m[1][i];
			j=2;if(c!='.')for(;j<=4;j++)if(m[j][i]!='T'&&m[j][i]!=c)break;
			if(j>4)w|=(c=='X'?1:2);
		}
		c=m[1][1]=='T'?m[2][2]:m[1][1];
		i=2;if(c!='.')for(;i<=4;i++)if(m[i][i]!='T'&&m[i][i]!=c)break;
		if(i>4)w|=(c=='X'?1:2);
		c=m[1][4]=='T'?m[2][3]:m[1][4];
		i=2;if(c!='.')for(;i<=4;i++)if(m[i][5-i]!='T'&&m[i][5-i]!=c)break;
		if(i>4)w|=(c=='X'?1:2);
		printf("Case #%d: %s\n",t,!w&&z?"Game has not completed":w==1?"X won":w==2?"O won":"Draw");
	}
}