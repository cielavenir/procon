fun main(args: Array<String>){
	val n=readLine()!!.toInt()
	var a=readLine()!!.split(" ").map(String::toInt).toMutableList()
	for(i in 0..n-1){
		var j=0
		while(a[j]!=0)j+=1
		for(k in 0..j)a[k]-=1
		print(""+(j+1)+" ")
	}
}
