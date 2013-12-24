object Solution {
	def main(args: Array[String]): Unit = {
		readLine()
		val a=readLine().split(' ').map(_.toInt)
		readLine()
		val b=readLine().split(' ').map(_.toInt)
		val m=b.min
		val z=new Array[Int](101)
		for(x<-a)z(x-m)-=1
		for(x<-b)z(x-m)+=1
		println( z.zipWithIndex.filter(_._1>0).map(_._2+m).mkString(" ") )
	}
}