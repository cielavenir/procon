object Solution extends App{
	def output(a:scala.collection.mutable.ListBuffer[Int]){
		if(a.length==0){
			println(-1)
		}else{
			print(a.head)
			if(a.length>1){
				print(' ')
				output(a.tail)
			}else{
				println()
			}
		}
	}
	val n=readLine().toInt
	for(i<-1 to n){
		val a=readLine().split(' ').map(_.toInt)
		val b=readLine().split(' ').map(_.toInt)
		val c=scala.collection.mutable.Map.empty[Int,Int]
		for(i<-0 to b.length-1){
			c(b(i))=c.getOrElse(b(i),0)+1
		}
		val r=scala.collection.mutable.ListBuffer[Int]()
		for(i<-0 to b.length-1){
			if(c(b(i))>=a(1)){
				r+=b(i)
				c(b(i))=0
			}
		}
		output(r)
	}
}