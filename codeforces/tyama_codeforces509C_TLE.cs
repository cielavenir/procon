using System;
using System.Collections.Generic;
class CodeForces509C{
	static private IEnumerable<List<int>> generate(int n,int prevn,int _digits){
		int d=n/9,r=n%9;
		List<int>a=new List<int>();
		int digits=Math.Max(_digits,(r==0?0:1)+d);
		//if(n<prevn)digits++;
		int z=digits-((r==0?0:1)+d);
		for(int i=0;i<z;i++)a.Add(0);
		if(r!=0)a.Add(r);
		for(int i=0;i<d;i++)a.Add(9);
		int idx;
		for(idx=0;idx<digits&&a[idx]==0;idx++);
		a[0]++;
		a[idx]--;
		for(;;){
			yield return a;
			int idx_down,idx_up=-1;
			for(idx_down=digits-1;idx_down>=0&&a[idx_down]==0;idx_down--);
			if(idx_down!=0){
				for(idx_up=idx_down-1;idx_up>=0&&a[idx_up]==9;idx_up--);
			}
			if(idx_up>=0){
				a[idx_down]--;
				a[idx_up]++;
				a.Reverse(idx_up+1,digits-(idx_up+1));
			}else{
				digits++;
				d=(n-1)/9;r=(n-1)%9;
				z=digits-(1+(r==0?0:1)+d);
				a.Clear();
				a.Add(1);
				for(int i=0;i<z;i++)a.Add(0);
				if(r!=0)a.Add(r);
				for(int i=0;i<d;i++)a.Add(9);
			}
		}
	}

	static private int compare(List<int>a,List<int>b){
		if(a.Count>b.Count)return -1;
		if(a.Count<b.Count)return 1;
		for(int i=0;i<a.Count;i++){
			if(a[i]>b[i])return -1;
			if(a[i]<b[i])return 1;
		}
		return 0;
	}

	static void Main(){
		List<int> cur=new List<int>();
		int prevn=0;
		int T=int.Parse(Console.ReadLine());
		for(int t=0;t<T;t++){
			int n=int.Parse(Console.ReadLine());
			IEnumerator<List<int>> gen=generate(n,prevn,cur.Count).GetEnumerator();
			for(;;){
				gen.MoveNext();
				List<int> nxt=gen.Current;
				if(compare(cur,nxt)==1){
					for(int i=0;i<nxt.Count;i++)Console.Write(nxt[i]);
					Console.WriteLine();
					cur=nxt;
					prevn=n;
					break;
				}
			}
		}
	}
}