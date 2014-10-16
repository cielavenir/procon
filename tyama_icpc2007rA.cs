using System;
using System.Linq;

class icpc2007rA{
	static int joseph(int n,int diff,int initial){
		int r=0,i=1;
		for(;i<n;i++)r=(r+diff)%i;
		return (r+1+initial)%n+1;
	}
	static void Main(){
		int[] a;
		for(;(a=Console.ReadLine().Split(' ').Select(int.Parse).ToArray())[0]>0;Console.WriteLine(joseph(a[0],a[1],a[2]-1)));
	}
}