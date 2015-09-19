using System;
class Player{
	static void Main(string[] args){
		for(;;){
			string enemy1 = Console.ReadLine(); // name of enemy 1
			int dist1 = int.Parse(Console.ReadLine()); // distance to enemy 1
			string enemy2 = Console.ReadLine(); // name of enemy 2
			int dist2 = int.Parse(Console.ReadLine()); // distance to enemy 2

			Console.WriteLine(dist1<dist2 ? enemy1 : enemy2);
		}
	}
}