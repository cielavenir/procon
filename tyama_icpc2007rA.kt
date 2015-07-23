import java.util.*
fun main(args: Array<String>){
	val cin = Scanner(System.`in`)
	while(true)
		val n=cin.nextInt()
		val k=cin.nextInt()
		val m=cin.nextInt()
		if(n==0)break
		var r=0
		for(i in 1..n-1)r=(r+k)%i
		println((r+m)%n+1)
	}
}