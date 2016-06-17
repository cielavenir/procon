import java.util.*
fun main(args: Array<String>){
	val cin=Scanner(System.`in`)
	var t=cin.nextInt()
	for(z in 0..t-1){
		val n=cin.nextInt()
		val m=cin.nextInt()
		val p=cin.nextInt()
		var i=1
		while(i<=p){
			if(p%i==0 && i<=n && p/i<=m)break
			i+=1
		}
		println(if(i<=p) "Yes" else "No")
	}
}