using System;
using System.Linq;
using System.Collections.Generic;
using System.Runtime.InteropServices;

class Hena24{
	[DllImport("c")]
	private extern static double cbrt(double d);

	static private IEnumerable<int> generate(){
		int i=1;
		for(;;){
			yield return i;
			i+=1;
		}
	}
	static private IEnumerable<int> drop_prev_square(IEnumerable<int> _prev){
		IEnumerator<int> prev=_prev.GetEnumerator();
		prev.MoveNext();
		int a=prev.Current;
		prev.MoveNext();
		int b=prev.Current;
		for(;;){
			int x=(int)Math.Sqrt(b);
			if(x*x!=b)yield return a;
			a=b;
			prev.MoveNext();
			b=prev.Current;
		}
	}
	static private IEnumerable<int> drop_next_square(IEnumerable<int> _prev){
		IEnumerator<int> prev=_prev.GetEnumerator();
		prev.MoveNext();
		int a=prev.Current;
		prev.MoveNext();
		int b=prev.Current;
		yield return a;
		for(;;){
			int x=(int)Math.Sqrt(a);
			if(x*x!=a)yield return b;
			a=b;
			prev.MoveNext();
			b=prev.Current;
		}
	}
	static private IEnumerable<int> drop_prev_cubic(IEnumerable<int> _prev){
		IEnumerator<int> prev=_prev.GetEnumerator();
		prev.MoveNext();
		int a=prev.Current;
		prev.MoveNext();
		int b=prev.Current;
		for(;;){
			int x=(int)cbrt(b);
			if(x*x*x!=b)yield return a;
			a=b;
			prev.MoveNext();
			b=prev.Current;
		}
	}
	static private IEnumerable<int> drop_next_cubic(IEnumerable<int> _prev){
		IEnumerator<int> prev=_prev.GetEnumerator();
		prev.MoveNext();
		int a=prev.Current;
		prev.MoveNext();
		int b=prev.Current;
		yield return a;
		for(;;){
			int x=(int)cbrt(a);
			if(x*x*x!=a)yield return b;
			a=b;
			prev.MoveNext();
			b=prev.Current;
		}
	}
	static private IEnumerable<int> drop_num(int n,IEnumerable<int> _prev){
		IEnumerator<int> prev=_prev.GetEnumerator();
		int i=0;
		for(;;){
			i++;
			prev.MoveNext();
			int a=prev.Current;
			if(i%n!=0)yield return a;
		}
	}
	static private IEnumerable<int> drop_cnt(int n,IEnumerable<int> _prev){
		IEnumerator<int> prev=_prev.GetEnumerator();
		int i=0;
		for(;;){
			i++;
			prev.MoveNext();
			int a=prev.Current;
			if(i>n)yield return a;
		}
	}
	static void Main(){
		var f=new Dictionary<char,Func<IEnumerable<int>,IEnumerable<int>>>(){
			{'S',drop_next_square},
			{'s',drop_prev_square},
			{'C',drop_next_cubic},
			{'c',drop_prev_cubic},
			{'h',e => drop_cnt(100,e)},
		};
		for(int i=2;i<10;i++){
			int j=i; //寿命が短いスコープを作ることで、ラムダ式のキャプチャでバグらないようにする。
			f[(char)('0'+j)] = e=>drop_num(j,e);
		}
		string line;
		for(;(line=Console.ReadLine())!=null;){
			bool first=true;
			foreach(int n in line.Aggregate(generate(),(s,e)=>f[e](s)).Take(10)){
				if(!first)Console.Write(',');
				first=false;
				Console.Write(n);
			}
			Console.WriteLine();
		}
	}
}