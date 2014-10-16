//usr/bin/env scala $0 $@;exit
object Solution{
	def main(args: Array[String]){
		val a=readLine()
		val b=readLine()
		for(i<-0 to a.length-1){
			print(a(i))
			print(b(i))
		}
	}
}