//usr/bin/env scala $0 $@;exit
import scala.util._
object Player{
	def main(args: Array[String]){
		while(true) {
			var name = ""
			var mi = 9999999.0
			val count = readInt
			for(i <- 0 until count){
				val Array(enemy, _dist) = readLine split " "
				val dist = _dist.toDouble
				if(mi>dist){
					mi=dist
					name=enemy
				}
			}
			println(name)
		}
	}
}