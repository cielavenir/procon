//usr/bin/env scala $0 $@;exit
object Solution{
	def main(args: Array[String]){
		val n=readLine().toInt
		for(i<-1 to n){
			val s=readLine().toCharArray()
			for(i<-1 to s.length()/2){
				val c=s((i-1)*2)
				s((i-1)*2)=s((i-1)*2+1)
				s((i-1)*2+1)=c
			}
			println(String.valueOf(s))
		}
	}
}