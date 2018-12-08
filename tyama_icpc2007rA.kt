fun main(args: Array<String>){
	while(true){
		val (n,k,m)=readLine()!!.split(" ").map(String::toInt)
		if(n==0)break
		var r=0
		for(i in 1..n-1)r=(r+k)%i
		println((r+m)%n+1)
	}
}
