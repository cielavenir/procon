object Solution extends App{
	val a = readLine()
	val r = Array("")
	for(c<-a)if(r(0).forall(_!=c))r(0)+=c
	println(r(0))
}