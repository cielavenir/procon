import kotlin.collections.*
fun main(args: Array<String>){
	val t=HashMap<Int,Int>()
	var a=readLine()!!.split(" ").map(String::toInt).toMutableList()
	a.removeAt(0)
	for(x in a){
		if(!t.containsKey(x))t.put(x,0)
		t.put(x,t.get(x)!!+1)
	}
	a=readLine()!!.split(" ").map(String::toInt).toMutableList()
	a.removeAt(0)
	for(x in a){
		if(!t.containsKey(x))t.put(x,0)
		t.put(x,t.get(x)!!-1)
	}
	var n=0
	for(m in t){
		if(m.value!=0)n+=1
	}
	print(n)
	val x=mutableListOf<Int>()
	for(m in t){
		if(m.value!=0)x.add(m.key)
	}
	x.sort()
	for(m in x){
		print(" "+m)
	}
	println()
}
