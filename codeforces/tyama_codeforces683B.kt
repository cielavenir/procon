import java.util.*
fun main(args: Array<String>){
	val cin=Scanner(System.`in`)
	val n=cin.nextInt()
	val a=Array(n,{i->""})
	val b=Array(n,{i->0})
	for(i in 0..n-1){
		a[i]=cin.next()
		b[i]=cin.nextInt()
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