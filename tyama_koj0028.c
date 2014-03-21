main(a,b){for(scanf("%d",&b);a<=b;a++){
	printf("%d:",a);
	if(a%5==0){
		if(a%3==0)puts("FizzBuzz");
		else puts("Buzz");
	}else{
		if(a%3==0)puts("Fizz");
		else puts("");
	}
}exit(0);}