object Solution{
	def main(args: Array[String]){
		val s=readInt()
		for(i<-1 to s){
			val Array(n,k)=readLine().split(" ").map(_.toInt)
			val a=new Array[Int](n+1)
			a(0)=1;a(1)=1
			for(j<-2 to n){
				for(k<-1 to j-1)a(j-k)=(a(j-k)+a(j-k-1))%100000007
				a(j)=1
			}
			println(a(k))
		}
	}
}