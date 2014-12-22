i,n;main(j){
	for(;i<256;i++){
		n=i^(i>>1); //gray code
		for(j=7;~j;j--)putchar(((n>>j)&1)+'0');
	}
}