//usr/bin/env scala $0 $@;exit
import scala.util.control.Breaks
object Solution{
	def main(args:Array[String]){
		val v=readInt()
		val n=readInt()
		val a=new Array[Int](v+1)
		a(0)=1
		val b = new Breaks
		b.breakable{
			for(i<-1 to v){
				val x=math.pow(i,n).toInt
				if(x>v)b.break
				for(j<-0 to v-x)a(v-j)+=a(v-j-x)
			}
		}
		println(a(v))
	}
}