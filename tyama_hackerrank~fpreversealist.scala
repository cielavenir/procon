object Solution extends App {
//answer
def g(a:List[Int],b:List[Int]):List[Int]={
	if(b.size==0){
		return a
	}else{
		return g(b.head::a,b.tail)
	}
}
def f(arr:List[Int]):List[Int]={
	return g(List(),arr)
}
//until here
  println(f(io.Source.stdin.getLines.toList.map(_.trim).map(_.toInt)).mkString("\n"))
}