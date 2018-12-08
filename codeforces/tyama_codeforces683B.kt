fun main(args: Array<String>){
	val n=readLine()!!.toInt()
	val a=mutableListOf<String>()
	val b=mutableListOf<Int>()
	for(i in 0..n-1){
		val (_a,_b)=readLine()!!.split(" ")
		a.add(_a)
		b.add(_b.toInt())
	}
	for(i in 0..n-2){
		for(j in 0..n-2-i){
			if(b[j]>b[j+1]){
				val x=b[j]
				b[j]=b[j+1]
				b[j+1]=x
				val y=a[j]
				a[j]=a[j+1]
				a[j+1]=y
			}
		}
	}
	for(e in a)println(e)
}
