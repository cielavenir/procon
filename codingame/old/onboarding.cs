using System;
class Player{
	static void Main(string[] args){
		for(;;){
			String name="";
			int n=int.Parse(Console.ReadLine());
			double mi=9999999;
			for(;n>0;n--){
				string[] inputs = Console.ReadLine().Split(' ');
				string enemy = inputs[0];
				double dist=double.Parse(inputs[1]);
				if(mi>dist){
					mi=dist;
					name=enemy;
				}
			}
			Console.WriteLine(name);
		}
	}
}