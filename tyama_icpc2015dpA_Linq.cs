using System;
using System.Linq;
class x{static void Main(){
	for(int a,b;;){
		String[] _=Console.ReadLine().Split();
		a=int.Parse(_[0]);
		b=int.Parse(_[1]);
		if(a==0)break;
		Console.WriteLine(Enumerable.Range(0,a/2+1).Select(i=>Math.Abs(b-Math.Sqrt(i*i+(a-i)*(a-i)))).Min());
	}
}}