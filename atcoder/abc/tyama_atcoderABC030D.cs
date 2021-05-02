using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;

class ABC030D{
	const int bufsiz=32;

	//MacPorts
	//const string libgmp="/opt/local/lib/libgmp.dylib";
	//ideone
	//const string libgmp="/usr/lib/i386-linux-gnu/libgmp.so.10";
	//paiza.io/atcoder
	const string libgmp="/usr/lib/x86_64-linux-gnu/libgmp.so.10";
	//wandbox/yukicoder
	//const string libgmp="/usr/lib64/libgmp.so.10";
	//AOJ
	//const string libgmp="/usr/lib64/libgmp.so.3";

	[DllImport("msvcrt",CallingConvention=CallingConvention.Cdecl)]static extern int write(int x,string y,int z);
	[DllImport("msvcrt",CallingConvention=CallingConvention.Cdecl)]static extern IntPtr fopen(string x,string y);
	[DllImport("msvcrt",CallingConvention=CallingConvention.Cdecl)]static extern int fflush(IntPtr x);
	[DllImport("msvcrt",CallingConvention=CallingConvention.Cdecl)]static extern int puts(string x);
	[DllImport("msvcrt",CallingConvention=CallingConvention.Cdecl)]static extern int system(string x);

	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_init(IntPtr x);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_clear(IntPtr x);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_out_str(IntPtr x,int y,IntPtr z);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_set_str(IntPtr x,string y,int z);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_set(IntPtr x,IntPtr y);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_set_si(IntPtr x,long y);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern int  __gmpz_cmp_si(IntPtr x,long y);

	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_add(IntPtr x,IntPtr y,IntPtr z);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_sub(IntPtr x,IntPtr y,IntPtr z);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_mul(IntPtr x,IntPtr y,IntPtr z);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_tdiv_q(IntPtr x,IntPtr y,IntPtr z);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_tdiv_r(IntPtr x,IntPtr y,IntPtr z);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_add_ui(IntPtr x,IntPtr y,long z);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_sub_ui(IntPtr x,IntPtr y,long z);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_mul_ui(IntPtr x,IntPtr y,long z);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_tdiv_q_ui(IntPtr x,IntPtr y,long z);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_tdiv_r_ui(IntPtr x,IntPtr y,long z);

	static void Main(){
		IntPtr stdout=fopen("/dev/stdout","w");

		String line;
		line=Console.ReadLine();
		String[] ar=line.Split(' ');
		int n=int.Parse(ar[0]);
		int a=int.Parse(ar[1]);
		line=Console.ReadLine();
		IntPtr k=Marshal.AllocHGlobal(bufsiz);__gmpz_init(k);
		__gmpz_set_str(k,line,10);
		line=Console.ReadLine();
		ar=line.Split(' ');
		int[] b=new int[n+1];
		for(int i=1;i<=n;i++)b[i]=int.Parse(ar[i-1]);

		Dictionary<int,int>h=new Dictionary<int,int>();
		int c=a;
		for(int i=0;;i++){
			if(h.ContainsKey(b[c])){
				int cycle=i-h[b[c]];
				__gmpz_tdiv_r_ui(k,k,cycle);
				break;
			}
			c=b[c];
			h[c]=i;
			__gmpz_sub_ui(k,k,1);
			if(__gmpz_cmp_si(k,0)==0)break;
		}
		for(;__gmpz_cmp_si(k,0)>0;){
			c=b[c];
			__gmpz_sub_ui(k,k,1);
		}
		Console.WriteLine(c);
		__gmpz_clear(k);Marshal.FreeHGlobal(k);
	}
}