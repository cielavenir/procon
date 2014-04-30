import scala.util.control.Breaks
object Main{
	def reverse[T](a: Array[T],start: Int,size: Int) = {
		val end=start+size-1
		for(i <- 0 to size/2-1){
			val z=a(start+i)
			a(start+i)=a(end-i)
			a(end-i)=z
		}
	}
	def next_permutation[T <% Ordered[T]](a: Array[T],n: Int): Boolean = {
		if(n<0||a.size<n)return false
		reverse(a,n,a.size-n)
		var k = -1
		val b = new Breaks
		b.breakable{
			for(i<-(a.size-2) to 0 by -1)if(a(i)<a(i+1)){k=i;b.break}
		}
		if(k<0){
			reverse(a,0,a.size)
			return false
		}
		var l = -1
		b.breakable{
			for(i<-a.size-1 to k+1 by -1)if(a(k).compare(a(i))<0){l=i;b.break}
		}
		val z=a(k);a(k)=a(l);a(l)=z
		reverse(a,k+1,a.size-(k+1))
		return true
	}
	def next_permutation[T <% Ordered[T]](a: Array[T]): Boolean = {
		return next_permutation(a,a.size)
	}
	def main(args: Array[String]) = {
		val N=6
		val b = new Breaks
		var r=0
		val e0=new Array[Int](N*2)
		val f0=new Array[Int](N*2)
		for(i<-Range(0,N)){e0(N+i)=1;f0(N+i)=1}
		val e=new Array[Int](N*2+1)
		val f=new Array[Int](N*2+1)
		do{
			for(i<-Range(0,N*2))e(i+1)=e(i)+e0(i)
			do{
				var flg=0
				var zero1=0
				var zero2=N
				var one1=0
				var one2=N
				for(i<-0 to N*2-1){
					if(e0(i)==0)zero1+=1
					if(e0(i)==1)one1+=1
					if(f0(N*2-1-i)==0)zero2-=1
					if(f0(N*2-1-i)==1)one2-=1
					if(zero1==zero2)flg+=1
					if(one1==one2)flg+=1
				}
				if(flg>=2)r+=1
			}while(next_permutation(f0))
		}while(next_permutation(e0))
		println(r);
	}
}