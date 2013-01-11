using System;
using System.Linq;

//61 === 5**3-4**3, 42 === 5**3-3**3-7*2**3
class atcoderwupc2D{
	static void Main(){
		Int64[] a=Console.ReadLine().Split(' ').Select(s=>Int64.Parse(s)).ToArray();
		a[1]-=7*a[2];
		if(a[1]<0){a[0]+=8*a[1];a[1]=0;}
		if(a[1]%8>0){a[0]-=8*(8-a[1]%8);a[1]+=8-a[1]%8;}
		a[1]/=8;
		a[0]-=61*a[3]+42*a[2]+61*a[1];
		if(a[0]<0)a[0]=0;
		Console.WriteLine(a[4]+a[3]+a[2]+a[1]+(a[0]+124)/125);
	}
}