// http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
// http://nabetani.sakura.ne.jp/hena/ord24eliseq/

using System;
using System.Linq;
using System.Collections.Generic;
//using System.Runtime.InteropServices;

class Hena24{
	//[DllImport("c")]
	//private extern static double cbrt(double d);

	static private int isqrt(int n){
		if(n<=0)return 0;
		if(n<4)return 1;
		int x=0,y=n;
		for(;x!=y&&x+1!=y;){x=y;y=(n/y+y)/2;}
		return x;
	}
	static private int icbrt(int n){
		if(n<0)return icbrt(-n);
		if(n==0)return 0;
		if(n<8)return 1;
		int x=0,y=n;
		for(;x!=y&&x+1!=y;){x=y;y=(n/y/y+y*2)/3;}
		return x;
	}

	static private bool is_sq(int n){
		//int x=(int)Math.Sqrt(n);
		int x=isqrt(n);
		return x*x==n;
	}
	static private bool is_cb(int n){
		//int x=(int)cbrt(n);
		int x=icbrt(n);
		return x*x*x==n;
	}
	static private bool is_multiple(int i,int n){return i%n==0;}
	static private bool is_le(int i,int n){return i<=n;}

	static private IEnumerable<int> generate(){
		int i=1;
		for(;;){
			yield return i;
			i+=1;
		}
	}
	static private IEnumerable<int> drop_prev(
		Func<int,bool> check,IEnumerable<int> _prev
	){
		IEnumerator<int> prev=_prev.GetEnumerator();
		prev.MoveNext();
		int a=prev.Current;
		prev.MoveNext();
		int b=prev.Current;
		for(;;){
			if(!check(b))yield return a;
			a=b;
			prev.MoveNext();
			b=prev.Current;
		}
	}
	static private IEnumerable<int> drop_next(
		Func<int,bool> check,IEnumerable<int> _prev
	){
		IEnumerator<int> prev=_prev.GetEnumerator();
		prev.MoveNext();
		int a=prev.Current;
		prev.MoveNext();
		int b=prev.Current;
		yield return a;
		for(;;){
			if(!check(a))yield return b;
			a=b;
			prev.MoveNext();
			b=prev.Current;
		}
	}
	static private IEnumerable<int> drop_n(
		Func<int,int,bool> check,int n,IEnumerable<int> _prev
	){
		IEnumerator<int> prev=_prev.GetEnumerator();
		int i=0;
		for(;;){
			i++;
			prev.MoveNext();
			int a=prev.Current;
			if(!check(i,n))yield return a;
		}
	}
	static void Main(){
		var f=new Dictionary<char,Func<IEnumerable<int>,IEnumerable<int>>>(){
			{'S',e => drop_next(is_sq,e)},
			{'s',e => drop_prev(is_sq,e)},
			{'C',e => drop_next(is_cb,e)},
			{'c',e => drop_prev(is_cb,e)},
			{'h',e => drop_n(is_le,100,e)},
		};
		for(int i=2;i<10;i++){
			int j=i; //寿命が短いスコープを作ることで、ラムダ式のキャプチャでバグらないようにする。
			f[(char)('0'+j)] = e=>drop_n(is_multiple,j,e);
		}
		string line;
		for(;(line=Console.ReadLine())!=null;){
			bool first=true;
			//cS => f['S'](f['c'](generate()))
			foreach(int n in line.Aggregate(generate(),(s,e)=>f[e](s)).Take(10)){
				if(!first)Console.Write(',');
				first=false;
				Console.Write(n);
			}
			Console.WriteLine();
			Console.Out.Flush();
		}
	}
}
