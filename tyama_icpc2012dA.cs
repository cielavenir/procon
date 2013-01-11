using System;
using System.Linq;

class icpc2012dA{
	static void Main(){
		int i,n;
		n=int.Parse(Console.ReadLine());
		for(i=0;i<n;i++){
			int[] a=Console.ReadLine().Split(' ').Select(s=>int.Parse(s)).ToArray();
			a[0]-=1;a[1]-=1;
			Console.WriteLine(196471-a[0]*195-a[0]/3*5-a[1]*20+(a[0]%3!=2?a[1]/2:0)-a[2]);
		}
	}
}