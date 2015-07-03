//usr/bin/env scala $0 $@;exit
object Solution{
	def main(args:Array[String]){
		//val n=readLine().toInt
		//for(i<-0 until n){
			val s=readLine()
			val x=new Array[Boolean](256)
			for(i<-0 until s.length){
				val c=s(i)
				if(!x(c)){
					x(c)=true
					print(c)
				}
			}
			println()
		//}
	}
}