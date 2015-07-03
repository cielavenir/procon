//usr/bin/env scala $0 $@;exit
object Solution{
	def main(args:Array[String]){
		val n=readLine().toInt
		for(i<-0 until n){
			val s=readLine()
			val x=new Array[Int](4)
			val i=new Array[Int](1)
			i(0)=0
			while(i(0)<s.length){
				if(s(i(0))=='R')x(0)+=1
				if(s(i(0))=='G')x(1)+=1
				if(s(i(0))=='Y')x(2)+=1
				if(s(i(0))=='B')x(3)+=1
				if(Math.abs(x(0)-x(1))>1 || Math.abs(x(2)-x(3))>1)i(0)=s.length
				i(0)+=1
			}
			if(i(0)==s.length && x(0)==x(1) && x(2)==x(3)){
				println("True")
			}else{
				println("False")
			}
		}
	}
}