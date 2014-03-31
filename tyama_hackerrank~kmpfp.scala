object Solution{
	def main(args:Array[String]){
		val n=readLine().toInt
		for(i<-1 to n){
			val s=readLine()
			val t=readLine()
			println(if(s.indexOf(t)>=0) "YES" else "NO")
		}
	}
}