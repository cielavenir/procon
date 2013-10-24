object Solution extends App {
//answer
def f(num:Int,arr:List[Int]):List[Int] = if(num==0||arr.isEmpty)List() else f(num-1,List(arr.head))++List(arr.head)++f(num,arr.tail)
//until here
  def displayResult(arr:List[Int]) = println(f(arr(0).toInt,arr.drop(1)).map(_.toString).mkString("\n"))

  displayResult(io.Source.stdin.getLines.toList.map(_.trim).map(_.toInt))
}