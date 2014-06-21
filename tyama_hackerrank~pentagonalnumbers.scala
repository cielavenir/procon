object Solution{
	def main(args:Array[String]){
		val n=readLine().toInt
		for(i<-1 to n){
			val x=readLine().toLong
			println((3*x*x-x)/2)
		}
	}
}