main(a,b){for(scanf("%d%d",&a,&b);a<=b;a++){
	if(a%5==0){
		if(a%3==0)puts("FizzBuzz");
		else puts("Buzz");
	}else{
		if(a%3==0)puts("Fizz");
		else printf("%d\n",a);
	}
}exit(0);}