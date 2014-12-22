//usr/bin/env scala $0 $@;exit
object Solution{
	def gcd(x:Int, y:Int): Int = {
		if(y==0) x else gcd(y,x%y)
	}
	def main(args:Array[String]){
		val n=readLine().toInt
		for(i<-1 to n){
			val a=readLine().split(' ').map(_.toInt)
			val g=gcd(a(0),a(1))
			val x=new Array[Int](1)
			for(i<-1 to math.sqrt(g).toInt){
				val r=g%i
				if(r==0){
					val d=g/i
					x(0) += (if(d==i) 1 else 2)
				}
			}
			println(x(0))
		}
	}
}