//usr/bin/env scala $0 $@;exit
object Main{
	def main(args:Array[String]){
		var n=0;
		val a=new Array[Int](31)
		a(0)=1
		a(1)=1
		a(2)=2
		for(i<- 3 to 30)a(i)=a(i-1)+a(i-2)+a(i-3)
		n=readInt()
		while(n>0){
			println((a(n)+3649)/3650)
			n=readInt()
		}
	}
}