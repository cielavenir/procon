import java.util.*
fun main(args: Array<String>){
	var i=0
	var x=0
	val cin=Scanner(System.`in`)
	val t=TreeMap<Int,Int>()
	var na=cin.nextInt()
	while(na>0){
		x=cin.nextInt()
		if(!t.containsKey(x))t.put(x,0)
		t.put(x,t.get(x)!!+1)
		na-=1
	}
	var nb=cin.nextInt()
	while(nb>0){
		x=cin.nextInt()
		if(!t.containsKey(x))t.put(x,0)
		t.put(x,t.get(x)!!-1)
		nb-=1
	}
	var n=0
	for(m in t){
		if(m.value!=0)n+=1
	}
	print(n)
	for(m in t){
		if(m.value!=0)print(" "+m.key)
	}
	println()
}