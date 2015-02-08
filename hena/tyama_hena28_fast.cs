// http://qiita.com/Nabetani/items/23ebddb44f0234e7fb15
// http://nabetani.sakura.ne.jp/hena/ord28spirwa/

using System;
using System.Runtime.InteropServices;

class Hena28{
#if __MonoCS__
	[DllImport("c", CallingConvention = CallingConvention.Cdecl)]
#else
	[DllImport("msvcr80", CallingConvention = CallingConvention.Cdecl)]
#endif
	private static extern int scanf(string format, out int a, out int b, out int c, out int d, out long e);

	static void Main(){
		string dir="ESWN";
		int n,e,s,w;
		long days;
		for(;scanf("%d,%d,%d,%d:%lld",out n,out e,out s,out w,out days)==5;){
			days+=1;
			int[] l=new int[]{e,s,w,n};
			int f=1;
			for(int i=0;f!=0;i++){
				int[] x=new int[]{l[i%4]+(i%4==0 ? 1 : 0),(i/4+1)*2,l[i%4]-(i%4==3 ? 1 : 0)};
				for(int j=0;j<3;j++){
					if(days-x[j]<0){
						Console.WriteLine(dir[(i+j)%4]);
						f=0;
						break;
					}
					days-=x[j];
				}
			}
			Console.Out.Flush();
		}
	}
}