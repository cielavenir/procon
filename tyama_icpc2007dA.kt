fun main(args: Array<String>){
	while(true){
		val n=readLine()!!.toInt()
		if(n==0)break
		var ma=0
		var mi=1000
		var s=0
		for(i in 0..n-1){
			var x=readLine()!!.toInt()
			if(x<mi)mi=x
			if(x>ma)ma=x
			s+=x
		}
		println(((s-ma-mi)/(n-2)).toString())
	}
}
