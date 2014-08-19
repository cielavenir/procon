c,S,s;
main(){
	for(;~(c=getchar());){
		if(__builtin_expect(c=='\n',0)){
			printf("lowercase: %.2f uppercase: %.2f\n",s*100.0/S,(S-s)*100.0/S);
			S=s=0;
		}else{
			if('a'<=c)s++;
			S++;
		}
	}
	printf("lowercase: %.2f uppercase: %.2f\n",s*100.0/S,(S-s)*100.0/S);
}