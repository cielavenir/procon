using System;
using System.Runtime.InteropServices;

class AOJ0015{
	const int bufsiz=32;

	//MacPorts
	//const string libgmp="/opt/local/lib/libgmp.dylib";
	//ideone
	//const string libgmp="/usr/lib/i386-linux-gnu/libgmp.so.10";
	//paiza.io/atcoder
	//const string libgmp="/usr/lib/x86_64-linux-gnu/libgmp.so.10";
	//wandbox/yukicoder
	const string libgmp="/usr/lib64/libgmp.so.10";
	//AOJ
	//const string libgmp="/usr/lib64/libgmp.so.3";

	[DllImport("msvcrt",CallingConvention=CallingConvention.Cdecl)]static extern int write(int x,string y,int z);
	[DllImport("msvcrt",CallingConvention=CallingConvention.Cdecl)]static extern IntPtr fopen(string x,string y);
	[DllImport("msvcrt",CallingConvention=CallingConvention.Cdecl)]static extern IntPtr fdopen(int x,string y);
	[DllImport("msvcrt",CallingConvention=CallingConvention.Cdecl)]static extern int fputs(string x,IntPtr y);
	[DllImport("msvcrt",CallingConvention=CallingConvention.Cdecl)]static extern int system(string x);

	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_init(IntPtr x);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_clear(IntPtr x);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_out_str(IntPtr x,int y,IntPtr z);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_set_str(IntPtr x,string y,int z);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_set(IntPtr x,IntPtr y);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern void __gmpz_set_si(IntPtr x,long y);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern int  __gmpz_cmp_si(IntPtr x,long y);
	[DllImport(libgmp,CallingConvention=CallingConvention.Cdecl)]static extern int  __gmpz_cmp(IntPtr x,IntPtr y);

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
		IntPtr a=Marshal.AllocHGlobal(bufsiz);__gmpz_init(a);
		IntPtr b=Marshal.AllocHGlobal(bufsiz);__gmpz_init(b);
		IntPtr c=Marshal.AllocHGlobal(bufsiz);__gmpz_init(c);
		__gmpz_set_str(c,"100000000000000000000000000000000000000000000000000000000000000000000000000000000",10);

		int T=int.Parse(Console.ReadLine());
		for(;T>0;T--){
			string A=Console.ReadLine();
			string B=Console.ReadLine();
			__gmpz_set_str(a,A,10);
			__gmpz_set_str(b,B,10);
			__gmpz_add(a,a,b);
			if(__gmpz_cmp(a,c)>=0){
				fputs("overflow\n",stdout);
			}else{
				__gmpz_out_str(stdout,10,a);
				fputs("\n",stdout);
			}
		}
	
		__gmpz_clear(a);Marshal.FreeHGlobal(a);
		__gmpz_clear(b);Marshal.FreeHGlobal(b);
		__gmpz_clear(c);Marshal.FreeHGlobal(c);
	}
}