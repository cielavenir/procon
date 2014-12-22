object Solution extends App {
//answer
def g(arr:List[Int]):List[Int] = if(arr.isEmpty)List() else List(arr.head)++(if(arr.tail.isEmpty)List() else g(arr.tail.tail))
def f(arr:List[Int]):List[Int] = g(arr.tail)
//antil here
  println(f(io.Source.stdin.getLines.toList.map(_.trim).map(_.toInt)).mkString("\n"))
}