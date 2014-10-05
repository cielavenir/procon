using System;
using System.Collections.Generic;
class CodeFormulaFinalE{
	static String s;
	static List<int>fib;
	static List<long>power2;
	static Dictionary<long,string>memo_small; //全キャッシュ。dfs()は実行するたびに速くなる。

	static string dfs(int n,int k,Dictionary<long,string>memo){
		if(n==1&&k==0)return "b";
		if(n==2&&k==0)return "a";
		long x=((long)n)<<32|k;
		if(memo.ContainsKey(x))return memo[x];
		if((k&1)!=0)return memo[x]=dfs(n-2,k/4,memo)+dfs(n-1,k/2,memo);
		return memo[x]=dfs(n-1,k/2,memo)+dfs(n-2,k/4,memo);
	}
	static IEnumerable<int> search(int level,int start){
	/*
		if(level==3){
			if(s.Substring(start,fib[level])=="ab")yield return 0;
			if(s.Substring(start,fib[level])=="ba")yield return 1;
			yield break;
		}
	*/
		if(level<15){
			for(int k=0;k<power2[level];k++){
				if(dfs(level,k,memo_small)==s.Substring(start,fib[level]))yield return k;
			}
			yield break;
		}
		if(s.Substring(start+fib[level-3],fib[level-2])==s.Substring(start+fib[level-3]+fib[level-2],fib[level-2])){
			foreach(int x in search(level-1,start))yield return x*2;
		}
		if(s.Substring(start,fib[level-2])==s.Substring(start+fib[level-2],fib[level-2])){
			foreach(int x in search(level-1,start+fib[level-2]))yield return x*2+1;
		}
		if(s.Substring(start,fib[level-2])==s.Substring(start+fib[level-3]+fib[level-2],fib[level-2])){
			foreach(int x in search(level-1,start+fib[level-2]))yield return x*2+1;
			foreach(int x in search(level-1,start))yield return x*2;
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
			memo_small=new Dictionary<long,string>();
		}
		s=Console.ReadLine();
		if(s=="b"){
			Console.WriteLine("1 0");
		}else if(s=="a"){
			Console.WriteLine("2 0");
		}else{
			int level=0;
			for(;level<fib.Count;level++)if(fib[level]==s.Length)break;
			HashSet<int> lst=new HashSet<int>();
			foreach(int x in search(level,0)){
				if(lst.Add(x)){
					Dictionary<long,string>memo=new Dictionary<long,string>();
					//Console.Error.WriteLine(x);
					if(dfs(level,x,memo)==s){
						Console.WriteLine(level.ToString()+" "+x.ToString());
						break;
					}
				}
			}
		}
	}
}