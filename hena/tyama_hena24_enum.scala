//usr/bin/env scala $0 $@;exit

// http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
// http://nabetani.sakura.ne.jp/hena/ord24eliseq/
import java.util.Map;
import java.util.HashMap
import java.util.Scanner
import java.util.Iterator
import java.util.function.Function
import java.util.function.BiFunction

object Hena24{
	def isqrt(n:Int):Int = {
		if(n<=0)return 0
		if(n<4)return 1
		var x=0
		var y=n
		while(x!=y&&x+1!=y){x=y;y=(n/y+y)/2}
		return x
	}
	def icbrt(n:Int):Int = {
		if(n<0)return icbrt(-n)
		if(n==0)return 0
		if(n<8)return 1
		var x=0
		var y=n
		while(x!=y&&x+1!=y){x=y;y=(n/y/y+y*2)/3}
		return x
	}
	class generate extends Iterator[Int]{
		var i=0
		def hasNext():Boolean = {return true}
		def next():Int = {
			i+=1
			return i
		}
	}
	class drop_prev(check:Function[Int,Boolean], prev:Iterator[Int]) extends Iterator[Int]{
		var a=0
		var b=prev.next()
		def hasNext():Boolean = {return true}
		def next():Int = {
			while(true){
				a = b
				b = prev.next()
				if(!check.apply(b)){
					return a
				}
			}
			assert(false); return -1
		}
	}
	class drop_next(check:Function[Int,Boolean], prev:Iterator[Int]) extends Iterator[Int]{
		var first = true
		var a=0
		var b=0
		def hasNext():Boolean = {return true}
		def next():Int = {
			while(true){
				a = b
				b = prev.next()
				if(first || !check.apply(a)){
					first = false
					return b
				}
			}
			assert(false); return -1
		}
	}
	class drop_n(check:BiFunction[Int,Int,Boolean], n:Int, prev:Iterator[Int]) extends Iterator[Int]{
		var i=0
		def hasNext():Boolean = {return true}
		def next():Int = {
			while(true){
				i+=1
				val a = prev.next()
				if(!check.apply(i,n)){
					return a
				}
			}
			assert(false); return -1
		}
	}
	def is_sq(n:Int):Boolean = {
		val x=isqrt(n)
		return x*x==n
	}
	def is_cb(n:Int):Boolean = {
		val x=icbrt(n)
		return x*x*x==n
	}
	def is_multiple(i:Int,n:Int):Boolean = {return i%n==0}
	def is_le(i:Int,n:Int):Boolean = {return i<=n}

	def main(z:Array[String]):Unit = {
		var f:Map[Character,Function[Iterator[Int],Iterator[Int]]] = new HashMap[Character,Function[Iterator[Int],Iterator[Int]]](){
			{
				put('S',(e:Iterator[Int])=>new drop_next(is_sq _,e))
				put('s',(e:Iterator[Int])=>new drop_prev(is_sq _,e))
				put('C',(e:Iterator[Int])=>new drop_next(is_cb _,e))
				put('c',(e:Iterator[Int])=>new drop_prev(is_cb _,e))
				put('h',(e:Iterator[Int])=>new drop_n(is_le _,100,e))
			}
		}
		for(i<-2 to 9){
			val j=i
			f.put(String.valueOf(i).charAt(0),(e:Iterator[Int])=>new drop_n(is_multiple _,j,e))
		}

		val cin = new Scanner(System.in)
		while(cin.hasNext()){
			val line = cin.nextLine()
			var first=true

			var z:Iterator[Int] = new generate()
			for(e<-line.toCharArray())z=f.get(e).apply(z)
			for(i<-1 to 10){
				var n=z.next()
				if(!first)System.out.print(',')
				first=false
				System.out.print(n)
			}
			System.out.print('\n')
			System.out.flush()
		}
	}
}
