fun main(args: Array<String>){
	val n=readLine()!!.toInt()
	for(i in 0..n-1){
		var (y,m,d)=readLine()!!.split(" ").map(String::toInt)
		y-=1
		m-=1
		var r=0
		if(y%3!=2)r=m/2
		println(196471-y*195-y/3*5-m*20+r-d)
	}
}
