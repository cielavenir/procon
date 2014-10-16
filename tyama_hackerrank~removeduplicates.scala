//usr/bin/env scala $0 $@;exit
object Solution{
	def main(args: Array[String]){
		val a = readLine()
		val r = Array("")
		for(c<-a)if(r(0).forall(_!=c))r(0)+=c
		println(r(0))
	}
}