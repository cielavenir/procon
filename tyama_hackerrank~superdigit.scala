object Solution extends App{
	val _a = readLine().split(" ")
	val r = Array[Long](0)
	for(c<-_a(0))r(0)+=c-'0'
	r(0)*=_a(1).toLong
	while(r(0)>9){
		val x = Array[Long](0)
		while(r(0)>0){
			x(0)+=r(0)%10
			r(0)/=10
		}
		r(0)=x(0)
	}
	println(r(0))
}