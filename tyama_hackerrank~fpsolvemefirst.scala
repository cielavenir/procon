object Solution extends App{
	println(io.Source.stdin.getLines().take(2).map(_.toInt).sum)
}