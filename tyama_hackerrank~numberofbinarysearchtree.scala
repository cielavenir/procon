object Solution{
	def main(args: Array[String]){
		val n=1000
		val a=new Array[Int](n+1)
		for(i<-0 to n)a(i)=1
		for(i<-2 to n){
			for(j<-i to n)a(j)=(a(j)+a(j-1))%100000007
		}
		val s=readLine().toInt
		for(i<-1 to s){
			val n=readLine().toInt
			println(a(n))
		}
	}
}