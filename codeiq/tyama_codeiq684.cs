using System;
using System.Collections.Generic;
class CodeIQRoute{
	static IEnumerable<List<T>> Permutation<T>(List<T> x) where T : IComparable<T>{
		List<T> a=new List<T>(x);
		a.Sort();
		int k=0;
		for(;;){
			int i;
			for(i=k;i<a.Count;i++)yield return a.GetRange(0,i+1);
			for(i=a.Count-2;i>=0;i--)if(a[i].CompareTo(a[i+1])<0)break;
			if(i<0)break;
			k=i;
			for(i=a.Count-1;i>=k+1;i--)if(a[k].CompareTo(a[i])<0)break;
			int l=i;
			T z=a[k];a[k]=a[l];a[l]=z;
			a.Reverse(k+1,a.Count-(k+1));
		}
	}
	static void Main(){
		long i=0;
		if(false){
			foreach(List<char> e in Permutation(new List<char>("aaabcc".ToCharArray()))){
				i+=1;
				Console.WriteLine(i.ToString()+":"+new String(e.ToArray()));
			}
		}else{
			foreach(List<char> e in Permutation(new List<char>("abbbbcddddeefggg".ToCharArray()))){
				i+=1;
				if(e.Count==8&&new String(e.ToArray())=="eagcdfbe"){Console.WriteLine(i);break;}
			}
		}
	}
}