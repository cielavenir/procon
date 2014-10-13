using System;
using System.Linq;
using System.Collections.Generic;
class CodeForces471B{
	static IEnumerable<List<T>> Permutation<T>(List<T> x,int? _n=null) where T : IComparable<T>{
		int n=_n ?? x.Count;
		if(n<0||x.Count<n)yield break;
		List<T> a=new List<T>(x);
		a.Sort();
		for(;;){
			yield return a.GetRange(0,n);
			int i;
			a.Reverse(n,a.Count-n);
			for(i=a.Count-2;i>=0;i--)if(a[i].CompareTo(a[i+1])<0)break;
			if(i<0){
				//a.Reverse(0,a.Count);
				/*yield*/ break;
			}
			int k=i;
			for(i=a.Count-1;i>=k+1;i--)if(a[k].CompareTo(a[i])<0)break;
			int l=i;
			T z=a[k];a[k]=a[l];a[l]=z;
			a.Reverse(k+1,a.Count-(k+1));
		}
	}
	static IEnumerable<List<int>> dfs(List<List<int>> list,int d,List<int>result){
		if(d==list.Count){
			yield return result;
		}else{
			int siz=result.Count;
			foreach(var e in Permutation(list[d])){
				result.AddRange(e);
				foreach(var _ in dfs(list,d+1,result))yield return _;
				result.RemoveRange(siz,e.Count);
			}
		}
	}
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		int[] a=Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
		SortedDictionary<int,List<int>> dict=new SortedDictionary<int,List<int>>();
		for(int i=0;i<n;i++){
			if(!dict.ContainsKey(a[i]))dict[a[i]]=new List<int>();
			dict[a[i]].Add(i+1);
		}
		List<List<int>> list=new List<List<int>>();
		long comb=1,threshold=3;
		foreach(var e in dict){
			if(comb<threshold)comb*=e.Value.Count;
			list.Add(e.Value);
		}
		if(comb<threshold){
			Console.WriteLine("NO");
		}else{
			Console.WriteLine("YES");
			int cnt=0;
			foreach(var e in dfs(list,0,new List<int>())){
				for(int i=0;i<e.Count;i++){
					if(i>0)Console.Write(" ");
					Console.Write(e[i]);
				}
				Console.WriteLine();
				cnt++;
				if(cnt==threshold)break;
			}
		}
	}
}