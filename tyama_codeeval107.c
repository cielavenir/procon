char str[99];
main(n,l,i,j){
	for(;~scanf("%s",str);printf("%d\n",n>l/2?l:n)){
		for(n=1,l=strlen(str);n<=l/2;n++){
			for(i=0;i<n;i++)if(str[i]!=str[i+n])break;
			if(i==n)break;
		}
	}
}