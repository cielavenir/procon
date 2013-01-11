main(z,Z,a,b,c,X,Y,A,f,i,j){for(;scanf("%d%d%d",&a,&b,&c),a;printf("%d %d\n",X,Y))
for(A=99999999,f=i=0;!f;i++)
	for(j=0;j<=i;j++)
		if(z=a*j-b*(i-j),(Z=a*j+b*(i-j))==c||z==c||z==-c)
			if(f=1,A>Z)A=Z,X=j,Y=i-j;
exit(0);}