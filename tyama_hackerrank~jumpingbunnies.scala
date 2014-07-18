object Solution{
	def gcd(x:Long, y:Long): Long = {
		if(y==0) x else gcd(y,x%y)
	}
	def main(args:Array[String]){
		readLine()
		val a=readLine().split(' ').map(_.toLong)
		val x=new Array[Long](1)
		x(0)=1
		for(i<-0 to a.length-1){
			x(0)=x(0)/gcd(x(0),a(i))*a(i)
		}
		println(x(0))
	}
}