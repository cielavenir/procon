using System;
using System.Runtime.InteropServices;

class TrickyB{
	const string libc="libc.so.6";
	[DllImport(libc,CallingConvention=CallingConvention.Cdecl)]
	static extern int scanf(string format, out int a);
	[DllImport(libc,CallingConvention=CallingConvention.Cdecl)]
	static extern int scanf(string format, out long a, out long b, out long c);
	[DllImport(libc,CallingConvention=CallingConvention.Cdecl)]
	static extern int printf(string format);
	[DllImport(libc,CallingConvention=CallingConvention.Cdecl)]
	static extern int printf(string format, double a);
	[DllImport(libc,CallingConvention=CallingConvention.Cdecl)]
	static extern int printf(string format, double a, double b);

	static void Main(){
		string[]A;
		int T;
		//scanf("%d",out T);
		T=int.Parse(Console.ReadLine());
		for(;T>0;T--){
			long a=0,b=0,c=0;
			//scanf("%lld%lld%lld",out a,out b,out c);
			A=Console.ReadLine().Split(' ');
			a=long.Parse(A[0]);
			b=long.Parse(A[1]);
			c=long.Parse(A[2]);
			if(a==0){
				if(b==0)Console.WriteLine(c==0?"3":"0");
				else Console.WriteLine(String.Format("1 {0:f12}",-c*1.0/b));
			}else{
				if(a<0){a=-a;b=-b;c=-c;}
				double d=b*b-4.0*a*c;
				if(/*d==0*/Math.Abs(d)<1e-9)Console.WriteLine(String.Format("1 {0:f12}",-b/2.0/a));
				else if(d<0)Console.WriteLine("0");
				else{
					// acknowledgement: http://tricky.contest.atcoder.jp/submissions/120839
					double x,y;
					if(b>0){
						x = (-b-Math.Sqrt(d))/2/a;
						y = c*1.0/a/x;
					}else{
						y = (-b+Math.Sqrt(d))/2/a;
						x = c*1.0/a/y;
					}
					Console.WriteLine(String.Format("2 {0:f12} {1:f12}",x,y));
				}
			}
		}
	}
}
