using System;
using System.Collections.Generic;

class KCS1027C{
	static private String fractal(int depth,int n){
		if(depth==0)return "";
		string s=fractal(depth-1,n/10);
		return s+(n%10).ToString()+s;
	}
	static private IEnumerable<String> seq(int K){
		int M=1,L=0;
		for(;K>0;K/=2){
			if((K&1)==0)yield break;
			M*=10;
			L++;
		}
		for(int i=0;i<M;i++){
			yield return fractal(L,i);
		}
	}
	static void Main(){
		String[] A=Console.ReadLine().Split();
		int N=int.Parse(A[0]),K=int.Parse(A[1]);
		String S=Console.ReadLine();
		foreach(var sub in seq(K)){
			for(int i=0,j=0;i<N;i++){
				if(S[i]==sub[j] && ++j==K){
					Console.WriteLine("Found");
					return;
				}
			}
		}
		Console.WriteLine("Not Found");
	}
}