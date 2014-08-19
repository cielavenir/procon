char s[99999];a[99999],k;main(i){
	printf("0 ");
	for(scanf("%s",s);i<strlen(s);i++){
		for(;k>0&&s[i]!=s[k];)k=a[k-1];
		if(s[i]==s[k])k++;
		printf(i<strlen(s)-1?"%d ":"%d\n",k);
		a[i]=k;
	}
}