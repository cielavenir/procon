class myCalculator{
	int power(int n,int p) throws java.lang.Exception{
		if(n<0||p<0){
			throw new java.lang.Exception("n and p should be non-negative");
		}else if(n==0&&p>0){
			return 0;
		}else{
			int ret=1;
			for(;p>0;p--)ret*=n;
			return ret;
		}
	}
}