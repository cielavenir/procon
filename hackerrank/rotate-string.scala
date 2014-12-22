//usr/bin/env scala $0 $@;exit
object Solution{
	def main(args: Array[String]){
		val n=readLine().toInt
		for(i<-1 to n){
			val s=readLine()
			for(j<-1 to s.length){
				if(j>1)print(" ")
				print(s.substring(j)+s.substring(0,j))
			}
			println()
		}
	}
}