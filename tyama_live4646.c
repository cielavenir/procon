char s[299];main(N,i,j,r,m){
	for(scanf("%d\n",&N);N--;printf("%d\n",m))if(m=0,scanf("%s",s),strlen(s)>5){
		for(j=0;j<strlen(s)-5;j++){
			for(r=0,i=j;i<strlen(s);i++){
				if('0'<=s[i]&&s[i]<='9')r|=1;
				if('a'<=s[i]&&s[i]<='z')r|=2;
				if('A'<=s[i]&&s[i]<='Z')r|=4;
				if(r==7)break;
			}
			if(i<strlen(s)){
				i++;i-=j;if(i<6)i=6;
				if(m==0)m=i;
				if(m>i)m=i;
			}
		}
	}
}