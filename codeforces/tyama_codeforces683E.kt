import java.util.*
fun main(args: Array<String>){
	val cin=Scanner(System.`in`)
	var n=cin.nextInt()
	val a=Array(n,{i->0})
	for(i in 0..n-1){
		a[i]=cin.nextInt()
	}
	for(i in 0..n-1){
		var j=0
		while(a[j]!=0)j+=1
		for(k in 0..j)a[k]-=1
		print(""+(j+1)+" ")
	}
}