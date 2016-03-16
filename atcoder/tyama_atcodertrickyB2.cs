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
		int T;
		scanf("%d",out T);
		for(;T>0;T--){
			long a,b,c;
			scanf("%lld%lld%lld",out a,out b,out c);
			if(a==0){
				if(b==0)printf(c==0?"3\n":"0\n");
				else printf("1 %.12f\n",-c*1.0/b);
			}else{
				if(a<0){a=-a;b=-b;c=-c;}
				double d=b*b-4.0*a*c;
				if(/*d==0*/Math.Abs(d)<1e-9)printf("1 %.12f\n",-b/2.0/a);
				else if(d<0)printf("0\n");
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
					printf("2 %.12f %.12f\n",x,y);
				}
			}
		}
	}
}