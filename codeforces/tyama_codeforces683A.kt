import java.util.*
fun main(args: Array<String>){
	val cin=Scanner(System.`in`)
	val a=cin.nextInt()
	val x=cin.nextInt()
	val y=cin.nextInt()
	if(0<x&&x<a && 0<y&&y<a){
		println(0)
	}else if(x<0||a<x || y<0||a<y){
		println(2)
	}else{
		println(1)
	}
}