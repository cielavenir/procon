import java.util.*;
class Solution{
	static boolean solve(int N,int M,int[] a){
		Queue<Integer> q=new ArrayDeque<Integer>();
		q.add(0);
		a[0]=1;
		for(;!q.isEmpty();){
			int cur=q.poll();
			int[] x=new int[]{-1,1,M};
			for(int d: x){
				int nxt=cur+d;
				if(nxt>=N)return true;
				if(nxt>0&&a[nxt]==0){
					q.add(nxt);
					a[nxt]=1;
				}
			}
		}
		return false;
	}
	public static void main(String[]args){
		Scanner cin=new Scanner(System.in);
		int T=Integer.parseInt(cin.next());
		for(;T>0;T--){
			int N=Integer.parseInt(cin.next());
			int M=Integer.parseInt(cin.next());
			int[] a=new int[N];
			for(int i=0;i<N;i++)a[i]=Integer.parseInt(cin.next());
			System.out.println(solve(N,M,a) ? "YES" : "NO");
		}
	}
}