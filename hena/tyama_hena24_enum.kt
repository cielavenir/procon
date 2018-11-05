// http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
// http://nabetani.sakura.ne.jp/hena/ord24eliseq/

import kotlin.sequences.*
fun isqrt(n:Int):Int{
	if(n<=0)return 0
	if(n<4)return 1
	var x=0
	var y=n
	while(x!=y&&x+1!=y){x=y;y=(n/y+y)/2}
	return x
}
fun icbrt(n:Int):Int{
	if(n<0)return icbrt(-n)
	if(n==0)return 0
	if(n<8)return 1
	var x=0
	var y=n
	while(x!=y&&x+1!=y){x=y;y=(n/y/y+y*2)/3}
	return x
}
fun is_sq(n:Int):Boolean{
	val x=isqrt(n)
	return x*x==n
}
fun is_cb(n:Int):Boolean{
	val x=icbrt(n)
	return x*x*x==n
}
fun is_multiple(i:Int,n:Int):Boolean{return i%n==0}
fun is_le(i:Int,n:Int):Boolean{return i<=n}

fun generate():Sequence<Int>{
	return sequence{
		var i=1
		while(true){
			yield(i)
			i+=1
		}
	}
}
fun drop_prev(check:(Int)->Boolean,_prev:Sequence<Int>):Sequence<Int>{
	return sequence{
		val prev=_prev.iterator()
		var a=prev.next()
		var b=prev.next()
		while(true){
			if(!check(b))yield(a)
			a=b
			b=prev.next()
		}
	}
}
fun drop_next(check:(Int)->Boolean,_prev:Sequence<Int>):Sequence<Int>{
	return sequence{
		val prev=_prev.iterator()
		var a=prev.next()
		var b=prev.next()
		yield(a)
		while(true){
			if(!check(a))yield(b)
			a=b
			b=prev.next()
		}
	}
}
fun drop_n(check:(Int,Int)->Boolean,n:Int,_prev:Sequence<Int>):Sequence<Int>{
	return sequence{
		val prev=_prev.iterator()
		var i=0
		while(true){
			i+=1
			val a=prev.next()
			if(!check(i,n))yield(a)
		}
	}
}
fun main(args:Array<String>){
	val f: HashMap<Char,(Sequence<Int>)->Sequence<Int>> = hashMapOf(
		'S' to {e->drop_next(::is_sq,e)},
		's' to {e->drop_prev(::is_sq,e)},
		'C' to {e->drop_next(::is_cb,e)},
		'c' to {e->drop_prev(::is_cb,e)},
		'h' to {e->drop_n(::is_le,100,e)}
	)
	for(i in 2..9){
		f[('0'+i).toChar()] = fun(e)=drop_n(::is_multiple,i,e)
		//{e->drop_n(::is_multiple,i,e)} //both are OK
	}
	var line=readLine()
	while(line!=null){
		var first=true;
		//cS => f['S']!!(f['c']!!(generate()))
		for(n in line.toCharArray().fold(generate()){
			s,e->f[e]!!(s) //nullable? yippee
		}.take(10)){
			if(!first)print(',')
			first=false
			print(n)
		}
		println()
		//System.out.flush()
		line=readLine()
	}
}
