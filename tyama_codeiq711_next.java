import java.util.*;
class Main{
	static <T> void reverse(List<T> a,int start,int size){
		int end=start+size-1;
		for(;start<end;start++){
			T z=a.get(start);a.set(start,a.get(end));a.set(end,z);
			end--;
		}
	}
	static <T extends Comparable<? super T>> boolean next_permutation(List<T> a,int n){
		if(n<0||a.size()<n)return false;
		int i;
		reverse(a,n,a.size()-n);
		for(i=a.size()-2;i>=0;i--)if(a.get(i).compareTo(a.get(i+1))<0)break;
		if(i<0){
			reverse(a,0,a.size());
			return false;
		}
		int k=i;
		for(i=a.size()-1;i>=k+1;i--)if(a.get(k).compareTo(a.get(i))<0)break;
		int l=i;
		T z=a.get(k);a.set(k,a.get(l));a.set(l,z);
		reverse(a,k+1,a.size()-(k+1));
		return true;
	}
	static <T extends Comparable<? super T>> boolean next_permutation(List<T> a){
		return next_permutation(a,a.size());
	}

	static final int N=6;
	public static void main(String[]z){
		int r=0,i;
		List<Integer>e0=new ArrayList<Integer>(),f0=new ArrayList<Integer>();
		for(i=0;i<N;i++){e0.add(0);f0.add(0);}
		for(i=0;i<N;i++){e0.add(1);f0.add(1);}
		do{
			do{
				int flg=0;
				int zero1=0;
				int zero2=N;
				int one1=0;
				int one2=N;
				for(i=0;i<N*2;i++){
					if(e0.get(i)==0)zero1++;
					if(e0.get(i)==1)one1++;
					if(f0.get(N*2-1-i)==0)zero2--;
					if(f0.get(N*2-1-i)==1)one2--;
					if(zero1==zero2)flg++;
					if(one1==one2)flg++;
				}
				if(flg>=2)r++;
			}while(next_permutation(f0));
		}while(next_permutation(e0));
		System.out.println(r);
	}
}