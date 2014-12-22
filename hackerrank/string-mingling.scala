//usr/bin/env scala $0 $@;exit
object Solution{
	def main(args: Array[String]){
		val a=readLine()
		val b=readLine()
		for(i<-0 until a.length){
			print(a(i))
			print(b(i))
		}
	}
}