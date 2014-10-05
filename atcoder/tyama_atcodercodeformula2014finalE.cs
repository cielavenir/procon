using System;
using System.Collections.Generic;
class CodeFormulaFinalE{
	static String s;
	static List<int>fib;
	static List<long>power2;

	static IEnumerable<int> search(int level,int start){
		if(level==3){
			if(s.Substring(start,fib[level])=="ab")yield return 0;
			if(s.Substring(start,fib[level])=="ba")yield return 1;
			yield break;
		}
		if(s.Substring(start+fib[level-3],fib[level-2])==s.Substring(start+fib[level-3]+fib[level-2],fib[level-2])){
			foreach(int x in search(level-1,start))yield return x*2;
		}
		if(s.Substring(start,fib[level-2])==s.Substring(start+fib[level-3]+fib[level-2],fib[level-2])){
			foreach(int x in search(level-1,start))yield return x*2;
			foreach(int x in search(level-1,start+fib[level-2]))yield return x*2+1;
		}
		if(s.Substring(start,fib[level-2])==s.Substring(start+fib[level-2],fib[level-2])){
			foreach(int x in search(level-1,start+fib[level-2]))yield return x*2+1;
		}
	}
	static void Main(){
		{
			fib=new List<int>();
			fib.Add(0);
			fib.Add(1);
			fib.Add(1);
			power2=new List<long>();
			power2.Add(0);
			power2.Add(0);
			power2.Add(1);
			long K=1;
			int a=1,b=1,c,n=3;
			for(;n<=22;n++){
				c=a+b;
				a=b;b=c;
				fib.Add(b);
				power2.Add(K*=2);
			}
		}
		s=Console.ReadLine();
		if(s=="b"){
			Console.WriteLine("1 0");
		}else if(s=="a"){
			Console.WriteLine("2 0");
		}else{
			int level=0;
			for(;level<fib.Count;level++)if(fib[level]==s.Length)break;
			foreach(int x in search(level,0)){
				Console.WriteLine(level.ToString()+" "+x.ToString());
				break;
			}
		}
	}
}