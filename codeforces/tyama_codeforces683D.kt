fun main(args: Array<String>){
	val t=readLine()!!.toInt()
	for(z in 0..t-1){
		val (n,m,p)=readLine()!!.split(" ").map(String::toInt)
		var i=1
		while(i<=p){
			if(p%i==0 && i<=n && p/i<=m)break
			i+=1
		}
		println(if(i<=p) "Yes" else "No")
	}
}
